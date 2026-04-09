#ifndef CINDER_NATURE_OF_CODE_WALKER_H
#define CINDER_NATURE_OF_CODE_WALKER_H

#include "cinder/Rand.h"
#include "cinder/app/AppBase.h"

using namespace ci;
using namespace ci::app;

class Walker
{
public:
    vec2 mPos;
    std::vector<vec2> mPosHistory;

    Walker()
    {
        mPos.x = getWindowWidth() / 2.0f;
        mPos.y = getWindowHeight() / 2.0f;
    };

    void step(float scale = 1.0f)
    {
        switch (randInt(4))
        {
        case 0:
            mPos.x += 1.0f * scale;
            break;
        case 1:
            mPos.x -= 1.0f * scale;
            break;
        case 2:
            mPos.y += 1.0f * scale;
            break;
        case 3:
            mPos.y -= 1.0f * scale;
            break;
        default:
            break;
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

#endif //CINDER_NATURE_OF_CODE_WALKER_H
