#include "OverhaulDetection.h"
#include "Global.h"

#include <cstdio>
#include <cstring>

namespace {
    // Files unique to known overhaul mods; any one present in ftl.dat proves an
    // overhaul was patched in. Patching only adds or replaces files, so these
    // survive any mods stacked on top.
    const char *const overhaulFingerprints[] = {
        "data/events_special_multiverse.xml", // Multiverse
        "img/achievements/insach_stonks.png", // Insurrection+
        "data/is_overhaul_mod.xml", // Opt-in marker any overhaul can ship, see wiki/Hyperspace.xml.md
    };

    bool overhaulDetected = false;
    bool basemodXmlActive = false;
}

void OverhaulDetection::ScanPackage(ResourceControl *resources)
{
    PackageModuleInfo *package = resources->package;
    if (!package || !package->list_files_start || !package->list_files_next) return;

    package->list_files_start(package);
    for (const char *pkgFile; !overhaulDetected && (pkgFile = package->list_files_next(package)) != nullptr;)
    {
        for (const char *fingerprint : overhaulFingerprints)
        {
            if (strcmp(pkgFile, fingerprint) == 0)
                overhaulDetected = true;
        }
    }

    printf("ftl.dat scan: overhaul mod: %s\n", overhaulDetected ? "detected" : "not found");
}

void OverhaulDetection::SetBasemodXml(bool isBasemod)
{
    basemodXmlActive = isBasemod;
}

void OverhaulDetection::CheckPatchOrder()
{
    if (overhaulDetected && basemodXmlActive)
        ErrorMessage("Wrong mod patch order!\nhyperspace.ftl must be patched before overhaul mods like Multiverse or Insurrection+.\nRe-patch in the order given by your mod's install instructions.\n");
}
