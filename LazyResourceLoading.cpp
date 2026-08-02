#include "Global.h"


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

// Rewritten by canadahonk - slight changes made to save extremely much ram
HOOK_METHOD_PRIORITY(ResourceControl, PreloadResources, 9999, (bool preloadPlayerShips) -> bool)
{
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

            if (loadImage && false) // && !HonkSettings::LazyImageLoading)
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
                resourceId = resource_load_sound(resmgr, filename, 0);
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
            Sound* sound = resource_get_sound(resmgr, info.resId);
            if (sound != nullptr)
            {
                G_->GetSoundControl()->AddSoundFile(info.path, sound);
                // SoundControl::Sounds.AddSoundFile(info.path, sound);
            }
        }
        else if (StartsWithCaseInsensitive(
                     info.path.c_str(), "audio/music/", 12))
        {
            Sound* sound = resource_get_sound(resmgr, info.resId);
            if (sound != nullptr)
            {
                G_->GetSoundControl()->AddMusicStream(info.path, sound);
                // SoundControl::Sounds.AddMusicStream(info.path, sound);
            }
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

    // ftl_log("Resource Preload: %.3f\n", time_now() - startTime);
    BindAtlases();
    return true;
}
