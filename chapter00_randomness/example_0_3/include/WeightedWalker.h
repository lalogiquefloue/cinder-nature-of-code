#ifndef CINDER_NATURE_OF_CODE_WEIGHTED_WALKER_H
#define CINDER_NATURE_OF_CODE_WEIGHTED_WALKER_H

#include "cinder/Rand.h"
#include "cinder/app/AppBase.h"

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
    glm::vec2 pos;
    std::vector<glm::vec2> pos_history;
    StepWeights mWeights;

    WeightedWalker() : mWeights{0.25f, 0.25f, 0.25f, 0.25f}
    {
        pos.x = cinder::app::getWindowWidth() / 2.0f;
        pos.y = cinder::app::getWindowHeight() / 2.0f;
    };

    WeightedWalker(StepWeights probs) : mWeights(probs)
    {
        pos.x = cinder::app::getWindowWidth() / 2.0f;
        pos.y = cinder::app::getWindowHeight() / 2.0f;
    };

    void step(float scale = 1.0f)
    {
        float thresholdUp = mWeights.up;
        float thresholdDown = thresholdUp + mWeights.down;
        float thresholdLeft = thresholdDown + mWeights.left;
        float totalWeight = thresholdLeft + mWeights.right;

        float r = cinder::randFloat(totalWeight);

        if (r < thresholdUp)
        {
            pos.y += 1.0f * scale;
        }
        else if (r < thresholdDown)
        {
            pos.y -= 1.0f * scale;
        }
        else if (r < thresholdLeft)
        {
            pos.x -= 1.0f * scale;
        }
        else
        {
            pos.x += 1.0f * scale;
        }

        pos_history.push_back(pos);
    }

    const std::vector<glm::vec2>& getPosHistory() const
    {
        return pos_history;
    }

    void reset()
    {
        pos_history.clear();
        pos.x = cinder::app::getWindowWidth() / 2.0f;
        pos.y = cinder::app::getWindowHeight() / 2.0f;
    }
};

#endif //CINDER_NATURE_OF_CODE_WEIGHTED_WALKER_H
