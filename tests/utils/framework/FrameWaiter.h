#pragma once

/**
 * TestFramework::FrameWaiter
 *
 * Frame-based timing utilities for tests.
 * Helps tests wait for specific numbers of frames or synchronize with game loop.
 */

namespace TestFramework
{
    /**
     * Helper for waiting specific numbers of frames in tests
     */
    class FrameWaiter
    {
    public:
        FrameWaiter();

        void reset();
        void tick();
        bool waitedFrames(int frames);
        int getFrameCount() const { return frameCount; }

    private:
        int frameCount;
    };
}
