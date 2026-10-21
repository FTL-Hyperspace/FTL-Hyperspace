#ifdef __APPLE__

#include "FreezeWatchdog.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>

namespace FreezeWatchdog {

static bool initForceExitOnFreeze()
{
    const char* envVar = std::getenv("HYPERSPACE_FORCE_EXIT_ON_FREEZE");
    return envVar != nullptr && std::string(envVar) == "1";
}

static const bool FORCE_EXIT_ON_FREEZE = initForceExitOnFreeze();

static pid_t g_gamePid = 0;
static pid_t g_watchdogPid = 0;
static std::string g_heartbeatFile;
static uint64_t g_lastHeartbeat = 0;

static constexpr int FREEZE_TIMEOUT_SECONDS = 5;
static constexpr int GRACE_PERIOD_SECONDS = 15;
static constexpr int WAKE_GRACE_SECONDS = 10;
static constexpr uint64_t HEARTBEAT_INTERVAL_MS = 1000;

static uint64_t GetCurrentTimeMs()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return static_cast<uint64_t>(ts.tv_sec) * 1000 + static_cast<uint64_t>(ts.tv_nsec) / 1000000;
}

static bool TouchFile(const std::string& path)
{
    FILE* f = fopen(path.c_str(), "w");
    if (f)
    {
        fclose(f);
        return true;
    }
    return false;
}

static bool FileExists(const std::string& path)
{
    struct stat st;
    return stat(path.c_str(), &st) == 0;
}

static time_t GetModifiedTime(const std::string& path)
{
    struct stat st;
    if (stat(path.c_str(), &st) != 0)
    {
        return -1;
    }
    return st.st_mtime;
}

// Stops while the Mac sleeps
static uint64_t GetAwakeSeconds()
{
    return clock_gettime_nsec_np(CLOCK_UPTIME_RAW) / 1000000000ull;
}

// Time the Mac spent asleep, from a clock that keeps counting during sleep and one that stops
static int64_t GetSleptNanoseconds()
{
    return (int64_t)clock_gettime_nsec_np(CLOCK_MONOTONIC) - (int64_t)clock_gettime_nsec_np(CLOCK_UPTIME_RAW);
}

static bool ShowFreezeDialog()
{
    // Use osascript to show a dialog and capture the button clicked
    // activate brings the dialog in front of the frozen game window
    const char* script =
        "osascript -e 'activate' -e 'button returned of (display dialog "
        "\"FTL appears to be frozen. Would you like to force quit?\" "
        "buttons {\"Wait\", \"Force Quit\"} "
        "default button \"Wait\" "
        "with icon caution "
        "with title \"Hyperspace Freeze Detected\")'";

    FILE* pipe = popen(script, "r");
    if (!pipe)
    {
        return false;
    }

    char buffer[128];
    std::string result;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        result += buffer;
    }
    pclose(pipe);

    // Remove trailing newline
    while (!result.empty() && (result.back() == '\n' || result.back() == '\r'))
    {
        result.pop_back();
    }

    return result == "Force Quit";
}

static void WatchdogLoop()
{
    time_t lastHeartbeatModified = GetModifiedTime(g_heartbeatFile);
    uint64_t lastHeartbeatAwake = GetAwakeSeconds();
    int64_t lastSlept = GetSleptNanoseconds();

    while (true)
    {
        sleep(1);

        // Game process dead? Exit watchdog.
        if (kill(g_gamePid, 0) != 0)
        {
            break;
        }

        // Heartbeat file gone? Clean exit signal.
        if (!FileExists(g_heartbeatFile))
        {
            break;
        }

        uint64_t awake = GetAwakeSeconds();
        int64_t slept = GetSleptNanoseconds();

        // Woke from sleep, give the game time to send heartbeats again
        if (slept - lastSlept > 1000000000ll)
        {
            lastHeartbeatAwake = awake + WAKE_GRACE_SECONDS;
        }
        lastSlept = slept;

        time_t modified = GetModifiedTime(g_heartbeatFile);
        if (modified != lastHeartbeatModified)
        {
            lastHeartbeatModified = modified;
            lastHeartbeatAwake = awake;
        }

        // Stale heartbeat, counting only time the Mac was awake
        if (awake > lastHeartbeatAwake && awake - lastHeartbeatAwake > FREEZE_TIMEOUT_SECONDS)
        {
            if (FORCE_EXIT_ON_FREEZE)
            {
                // Auto-exit mode - immediately kill without dialog
                kill(g_gamePid, SIGKILL);
                break;
            }
            else if (ShowFreezeDialog())
            {
                // User chose Force Quit
                kill(g_gamePid, SIGKILL);
                break;
            }
            else
            {
                // User chose Wait - grace period before next check
                sleep(GRACE_PERIOD_SECONDS);
            }
        }
    }

    // Cleanup heartbeat file if it still exists
    unlink(g_heartbeatFile.c_str());
}

void Start()
{
    g_gamePid = getpid();
    g_heartbeatFile = "/tmp/hs_heartbeat_" + std::to_string(g_gamePid);

    // Create initial heartbeat file
    TouchFile(g_heartbeatFile);
    g_lastHeartbeat = GetCurrentTimeMs();

    g_watchdogPid = fork();
    if (g_watchdogPid == 0)
    {
        // Child process - run watchdog loop
        WatchdogLoop();
        _exit(0);
    }
    // Parent process continues normally
}

void SendHeartbeat()
{
    uint64_t now = GetCurrentTimeMs();
    if (now - g_lastHeartbeat > HEARTBEAT_INTERVAL_MS)
    {
        TouchFile(g_heartbeatFile);
        g_lastHeartbeat = now;
    }
}

void Stop()
{
    // Delete heartbeat file to signal clean exit to watchdog
    unlink(g_heartbeatFile.c_str());
}

} // namespace FreezeWatchdog

#endif // __APPLE__
