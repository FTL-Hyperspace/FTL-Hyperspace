#pragma once

class ResourceControl;

namespace OverhaulDetection {
    // Fingerprint ftl.dat's file listing for patched mods. Called from the
    // ResourceControl::PreloadResources hook before resources load.
    void ScanPackage(ResourceControl *resources);

    // Record the <isBasemod> value from the active hyperspace.xml. Called from
    // hyperspace.xml early parsing; defaults to false when the tag is absent.
    void SetBasemodXml(bool isBasemod);

    // Warn if overhaul data is in the dat but the base mod's hyperspace.xml is
    // the active one (hyperspace.ftl patched after the overhaul). Must be called
    // after hyperspace.xml has been parsed.
    void CheckPatchOrder();
}
