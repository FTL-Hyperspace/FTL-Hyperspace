#include "FrameWaiter.h"

namespace TestFramework
{
    FrameWaiter::FrameWaiter()
        : frameCount(0)
    {
    }

    void FrameWaiter::reset()
    {
        frameCount = 0;
    }

    void FrameWaiter::tick()
    {
        frameCount++;
    }

    bool FrameWaiter::waitedFrames(int frames)
    {
        return frameCount >= frames;
    }
}
