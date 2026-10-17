#include "Global.h"
#include "CustomOptions.h"
#include <cstring>


// These are actually globals but we only need them in this file and than to canadahonk we have full replicas
bool StartsWithCaseInsensitive(const char* value, const char* prefix, std::size_t length)
{
    return strncasecmp(value, prefix, length) == 0;
}
bool HasExtensionCaseInsensitive(const char* path, const char* extension)
{
    const std::size_t pathLength = std::strlen(path);
    const std::size_t extensionLength = std::strlen(extension);
    return pathLength >= extensionLength && strcasecmp(path + pathLength - extensionLength, extension) == 0;
}
std::string LogicalPngPath(const std::string& path)
{
    if (HasExtensionCaseInsensitive(path.c_str(), ".tex"))
    {
        return path.substr(0, path.size() - 4) + ".png";
    }
    return path;
}

#ifndef HS_ANDROID
// Rewritten by canadahonk - slight changes made to save extremely much ram
HOOK_METHOD_PRIORITY(ResourceControl, PreloadResources, 9999, (bool preloadPlayerShips) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ResourceControl::PreloadResources -> Begin (LazyResourceLoading.cpp)\n")

    constexpr double kFrameInterval = 1.0 / 60.0;
    constexpr float kFirstPhaseEnd = 0.15F;
    constexpr std::array<const char*, 10> kPlayableShipPrefixes = {
        "img/ship/anaerobic_cruiser_",
        "img/ship/circle_cruiser_",
        "img/ship/crystal_cruiser_",
        "img/ship/energy_cruiser_",
        "img/ship/fed_cruiser_",
        "img/ship/jelly_cruiser_",
        "img/ship/kestral_",
        "img/ship/mantis_cruiser_",
        "img/ship/rock_cruiser_",
        "img/ship/stealth_",
    };

    const double startTime = time_now();
    preLoadProgress = {0, 0};
    package->list_files_start(package);
    while (package->list_files_next(package) != nullptr)
    {
        ++preLoadProgress.second;
    }

    std::vector<LoadInfo> resourceList;
    resourceList.reserve(
        static_cast<std::size_t>(preLoadProgress.second));
    preLoadProgress.first = 0;
    package->list_files_start(package);
    double frameTimer = time_now() - 1.0;

    for (const char* filename = package->list_files_next(package);
         filename != nullptr;
         filename = package->list_files_next(package))
    {
        if (StartsWithCaseInsensitive(filename, "img/", 4))
        {
            if (StartsWithCaseInsensitive(
                    filename, "img/ships_noglow/", 17))
            {
                continue;
            }

            bool recognizedPlayerShip = false;
            for (const char* prefix : kPlayableShipPrefixes)
            {
                if (StartsWithCaseInsensitive(
                        filename, prefix, std::strlen(prefix)))
                {
                    recognizedPlayerShip = true;
                    break;
                }
            }

            bool playerShip = false;
            bool hangarImage = false;
            if (recognizedPlayerShip)
            {
                playerShip =
                    std::strstr(filename, "_cloak") != nullptr ||
                    std::strstr(filename, "_gib") != nullptr ||
                    std::strstr(filename, "_shields") != nullptr;
                hangarImage = !playerShip;
            }

            const bool topLevelShip =
                StartsWithCaseInsensitive(filename, "img/ship/", 9) &&
                std::strchr(filename + 9, '/') == nullptr;
            const bool glowShip = StartsWithCaseInsensitive(
                filename, "img/ships_glow/", 15);
            const bool enemyShip =
                (topLevelShip || glowShip) &&
                !recognizedPlayerShip;

            bool loadImage = true;
            if (imageSwappingMode != SWAP_NONE &&
                (enemyShip || recognizedPlayerShip))
            {
                loadImage = false;
                if (imageSwappingMode == SWAP_SHIP_SETS)
                {
                    loadImage =
                        preloadPlayerShips ? hangarImage : enemyShip;
                }
            }

            const std::string pngPath = LogicalPngPath(filename);
            if (playerShip)
            {
                playerShipImages.push_back(pngPath);
            }
            else if (hangarImage)
            {
                hangarShipImages.push_back(pngPath);
            }
            if (enemyShip)
            {
                enemyShipImages.push_back(pngPath);
            }

            if (loadImage && CustomOptionsManager::GetInstance()->disableLazyImageLoading.currentValue)
            {
                const int resourceId = LoadTexture(resmgr, filename);
                resourceList.push_back(
                    {filename, resourceId, resource_mark(resmgr)});
            }
        }
        else
        {
            int resourceId = 0;
            bool load = true;
            if (StartsWithCaseInsensitive(filename, "atlas/", 6))
            {
                resourceId = HasExtensionCaseInsensitive(filename, ".txt")
                                 ? resource_load_data(
                                       resmgr, filename, 0, 0x10)
                                 : LoadTexture(resmgr, filename);
            }
            else if (StartsWithCaseInsensitive(
                         filename, "audio/waves/", 12))
            {
            #ifndef WIN32
                resourceId = resource_load_sound(resmgr, filename, 0);
            #else
                resourceId = resource_load_data(resmgr, filename, 0, 0);
            #endif
            }
            else if (StartsWithCaseInsensitive(
                         filename, "audio/music/", 12))
            {
                resourceId = resource_open_sound(resmgr, filename);
            }
            else if (StartsWithCaseInsensitive(filename, "fonts/", 6))
            {
                resourceId = resource_load_data(resmgr, filename, 0, 0x10);
            }
            else
            {
                load = false;
            }

            if (load)
            {
                resourceList.push_back(
                    {filename, resourceId, resource_mark(resmgr)});
            }
        }

        ++preLoadProgress.first;
        if (time_now() - frameTimer > kFrameInterval)
        {
            RenderLoadingBarFrame(0.0F, kFirstPhaseEnd);
            frameTimer = time_now();
        }
        input_update();
        if (input_is_suspend_requested())
        {
            input_acknowledge_suspend_request();
        }
        if (input_is_quit_requested())
        {
            return false;
        }
    }

    preLoadProgress.second =
        static_cast<std::int32_t>(resourceList.size());
    atlasData.clear();
    preLoadProgress.first = 0;

    for (const LoadInfo& info : resourceList)
    {
        resource_wait(resmgr, info.mark);
        if (StartsWithCaseInsensitive(info.path.c_str(), "img/", 4))
        {
            BindImage(LogicalPngPath(info.path), info.resId);
        }
        else if (StartsWithCaseInsensitive(
                     info.path.c_str(), "atlas/", 6))
        {
            if (HasExtensionCaseInsensitive(info.path.c_str(), ".txt"))
            {
                const std::string physicalName =
                    info.path.substr(0, info.path.size() - 4);
                int size = 0;
                char* data = static_cast<char*>(
                    resource_get_data(resmgr, info.resId, &size));
                if (data != nullptr)
                {
                    ParseAtlas(data, size, physicalName);
                }
                resource_free(resmgr, info.resId);
            }
            else
            {
                BindImage(LogicalPngPath(info.path), info.resId);
            }
        }
        else if (StartsWithCaseInsensitive(
                     info.path.c_str(), "audio/waves/", 12))
        {
        #ifndef WIN32
            Sound* sound = resource_get_sound(resmgr, info.resId);
            if (sound != nullptr)
            {
                G_->GetSoundControl()->AddSoundFile(info.path, sound);
            }
        #else
            int size = 0;
            void* data = resource_get_data(resmgr, info.resId, &size);
            if (data != nullptr)
            {
                G_->GetSoundControl()->AddSoundFile(info.path, data, size);
            }
        #endif
        }
        else if (StartsWithCaseInsensitive(
                     info.path.c_str(), "audio/music/", 12))
        {
        #ifndef WIN32
            Sound* sound = resource_get_sound(resmgr, info.resId);
            if (sound != nullptr)
            {
                G_->GetSoundControl()->AddMusicStream(info.path, sound);
            }
        #else
            resource_free(resmgr, info.resId);
            int size = 0;
            int64_t offset = 0;
            if (resource_get_package_offsets(info.path.c_str() , &offset, &size) != 0)
            {
                G_->GetSoundControl()->AddMusicStream(info.path, offset, size);
            }
        #endif
        }
        else if (StartsWithCaseInsensitive(
                     info.path.c_str(), "fonts/", 6))
        {
            int size = 0;
            void* data = resource_get_data(resmgr, info.resId, &size);
            if (data != nullptr)
            {
                PreloadFont(data, size, info.path);
            }
            resource_free(resmgr, info.resId);
        }

        ++preLoadProgress.first;
        if (time_now() - frameTimer > kFrameInterval)
        {
            RenderLoadingBarFrame(kFirstPhaseEnd, 1.0F);
            frameTimer = time_now();
        }
        input_update();
        if (input_is_suspend_requested())
        {
            input_acknowledge_suspend_request();
        }
        if (input_is_quit_requested())
        {
            return false;
        }
    }

    hs_log_file("Resource Preload: %.3f\n", time_now() - startTime);
    // TODO: Figure out a way to use the normal ftl_log
    // ftl_log("Resource Preload: %.3f\n", time_now() - startTime);
    BindAtlases();
    return true;
}
#else
// FTL for iPad keeps its own art in atlases (atlas/*.tex), which stay preloaded, but loads
// every other image at start too, as the PC game does. Mods' images are .png files, and
// big mods have a lot of them (Multiverse's come to about 3.5 GB once decoded), which
// devices with 4 or 6 GB can't hold. The game loads an image the first time it's asked
// for (GetImageId calls EnsureImageLoaded), so, as above, the .png images are left out of
// the preload by hiding them from its file list.
static PackageListNextFunc g_listFilesNext = nullptr;
static int g_lazyImages = 0;

static const char* ListFilesNextWithoutImages(PackageModuleInfo* module)
{
    for (;;)
    {
        const char* filename = g_listFilesNext(module);
        if (filename == nullptr) return nullptr;
        // Localised images are bound by name here, so they stay
        if (StartsWithCaseInsensitive(filename, "img/", 4) && !StartsWithCaseInsensitive(filename, "img/loc-", 8) &&
            HasExtensionCaseInsensitive(filename, ".png"))
        {
            ++g_lazyImages;
            continue;
        }
        return filename;
    }
}

HOOK_METHOD_PRIORITY(ResourceControl, PreloadResources, 9999, (bool preloadPlayerShips) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ResourceControl::PreloadResources -> Begin (LazyResourceLoading.cpp)\n")
    if (CustomOptionsManager::GetInstance()->disableLazyImageLoading.currentValue || !package)
    {
        return super(preloadPlayerShips);
    }

    g_listFilesNext = package->list_files_next;
    package->list_files_next = ListFilesNextWithoutImages;
    g_lazyImages = 0;
    bool ret = super(preloadPlayerShips);
    package->list_files_next = g_listFilesNext;
    // The preload lists the files twice
    hs_log_file("Images left to load on first use: %d\n", g_lazyImages / 2);
    return ret;
}
#endif // HS_ANDROID
