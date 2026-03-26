#pragma once

#ifdef __APPLE__

namespace FreezeWatchdog {
    // Start the watchdog process. Called from launchHyperspace().
    void Start();

    // Send heartbeat signal. Called from a hook that runs every frame.
    void SendHeartbeat();

    // Signal clean shutdown. Called from CApp::OnExit hook.
    void Stop();
}

#endif // __APPLE__
