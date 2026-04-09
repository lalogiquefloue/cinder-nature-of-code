#ifndef CINDER_NATURE_OF_CODE_WEIGHTED_WALKER_H
#define CINDER_NATURE_OF_CODE_WEIGHTED_WALKER_H

#include "cinder/Rand.h"
#include "cinder/app/AppBase.h"

using namespace ci;
using namespace ci::app;

struct StepWeights
{
    float up;
    float down;
    float left;
    float right;
};

class WeightedWalker
{
public:
    vec2 mPos;
    std::vector<vec2> mPosHistory;
    StepWeights mWeights;

    WeightedWalker() : mWeights{0.25f, 0.25f, 0.25f, 0.25f}
    {
        mPos.x = getWindowWidth() / 2.0f;
        mPos.y = getWindowHeight() / 2.0f;
    };

    WeightedWalker(StepWeights probs) : mWeights(probs)
    {
        mPos.x = getWindowWidth() / 2.0f;
        mPos.y = getWindowHeight() / 2.0f;
    };

    void step(float scale = 1.0f)
    {
        float thresholdUp = mWeights.up;
        float thresholdDown = thresholdUp + mWeights.down;
        float thresholdLeft = thresholdDown + mWeights.left;
        float totalWeight = thresholdLeft + mWeights.right;

        float r = randFloat(totalWeight);

        if (r < thresholdUp)
        {
            mPos.y += 1.0f * scale;
        }
        else if (r < thresholdDown)
        {
            mPos.y -= 1.0f * scale;
        }
        else if (r < thresholdLeft)
        {
            mPos.x -= 1.0f * scale;
        }
        else
        {
            mPos.x += 1.0f * scale;
        }

        mPosHistory.push_back(mPos);
    }

    const std::vector<vec2>& getPosHistory() const
    {
        return mPosHistory;
    }

    void reset()
    {
        mPosHistory.clear();
        mPos.x = getWindowWidth() / 2.0f;
        mPos.y = getWindowHeight() / 2.0f;
    }
};

#endif //CINDER_NATURE_OF_CODE_WEIGHTED_WALKER_H
