#ifndef CINDER_NATURE_OF_CODE_PERLINWALKER_H
#define CINDER_NATURE_OF_CODE_PERLINWALKER_H

#include "cinder/Perlin.h"
#include "cinder/Rand.h"
#include "cinder/app/AppBase.h"
#include "cinder/CinderMath.h"

#define MAX_SIZE 1000

using namespace ci;
using namespace ci::app;

class PerlinWalker
{
public:
    vec2 mPos;
    std::deque<vec2> mPosHistory;

    Perlin mPerlin;
    float mTx = 0.0f;
    float mTy = 10000.0f;

    PerlinWalker()
    {
        mPerlin = Perlin(4, 42);
        mPos.x = getWindowWidth() / 2.0f;
        mPos.y = getWindowHeight() / 2.0f;
    };

    void step(float scale = 1.0f)
    {
        float nx = mPerlin.fBm(mTx, 0.0f);
        float ny = mPerlin.fBm(mTy, 100.0f);

        // Investigate the usage of the "noise" Perlin method, seems to converge towards center in a cross pattern
        // fBm is instead used to get the desired effect
        // float nx = perlin.noise(tx, 0.0f);
        // float ny = perlin.noise(ty, 100.0f);

        mPos.x = lmap(nx, -1.0f, 1.0f, 0.0f, static_cast<float>(getWindowWidth()));
        mPos.y = lmap(ny, -1.0f, 1.0f, 0.0f, static_cast<float>(getWindowHeight()));

        mTx += 0.001f * scale;
        mTy += 0.001f * scale;

        mPosHistory.push_back(mPos);
        if (mPosHistory.size() > MAX_SIZE)
        {
            mPosHistory.pop_front();
        }
    }

    const std::deque<vec2>& getPosHistory() const
    {
        return mPosHistory;
    }

    void reset()
    {
        mPosHistory.clear();

        // new seed
        mPerlin = Perlin(4, randInt());

        // reset position
        mTx = 0.0f;
        mTy = 10000.0f;
        mPos.x = getWindowWidth() / 2.0f;
        mPos.y = getWindowHeight() / 2.0f;
    }
};

#endif //CINDER_NATURE_OF_CODE_PERLINWALKER_H
