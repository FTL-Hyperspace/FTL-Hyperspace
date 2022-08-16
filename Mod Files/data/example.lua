print("Hyperspace version from Lua: " .. tostring(Hyperspace.version))
print(Hyperspace.version:toIdentifierString())
print("hello from CFPS SpeedFactor: " .. Hyperspace.FPS.SpeedFactor)
function helloCallback2()
    print("Hello Number 2")
end
function helloWorld()
    print("!!!!!!Hello World!!!!!!")
end
log("LUA MESSAGE")
script.on_load(helloWorld)
script.on_load(helloCallback2)
script.on_load(helloWorld)
