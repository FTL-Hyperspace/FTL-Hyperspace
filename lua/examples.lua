
print("Hyperspace version from Lua: " .. tostring(Hyperspace.version))
print(Hyperspace.version)
print(Hyperspace.version:toVersionString()) -- same as Hyperspace.version's tostring
print(Hyperspace.version:toIdentifierString())
print(Hyperspace.version.major)
print(Hyperspace.version.minor)
print(Hyperspace.version.patch)
print(Hyperspace.version:isFeatureBuild())
print(Hyperspace.version:getFeatureName())
print(Hyperspace.version:getDeprecatedIntegerVersion())
