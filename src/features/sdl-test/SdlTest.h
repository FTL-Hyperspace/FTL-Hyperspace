#pragma once

// Manual check that SDL3 works from inside Hyperspace. Draws what it finds over the game and beeps
// when a gamepad button is pressed. Uncomment the define to build it in.
//#define HS_TEST_SDL

#ifdef HS_TEST_SDL

namespace SdlTest {
    // Bring up the SDL subsystems that do not need the macOS main thread. Called from CApp::OnInit.
    void Init();

    // Draw the findings and poll the gamepad. Called from a hook that runs every frame.
    void Render();
}

#endif // HS_TEST_SDL
