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
    vec2 pos;
    std::deque<vec2> pos_history;

    Perlin perlin;
    float tx = 0.0f;
    float ty = 10000.0f;

    PerlinWalker()
    {
        perlin = Perlin(4, 42);
        pos.x = getWindowWidth() / 2.0f;
        pos.y = getWindowHeight() / 2.0f;
    };

    void step(float scale = 1.0f)
    {
        float nx = perlin.fBm(tx, 0.0f);
        float ny = perlin.fBm(ty, 100.0f);

        // Investigate the usage of the "noise" Perlin method, seems to converge towards center in a cross pattern
        // fBm is instead used to get the desired effect
        // float nx = perlin.noise(tx, 0.0f);
        // float ny = perlin.noise(ty, 100.0f);

        pos.x = lmap(nx, -1.0f, 1.0f, 0.0f, (float)getWindowWidth());
        pos.y = lmap(ny, -1.0f, 1.0f, 0.0f, (float)getWindowHeight());

        tx += 0.001f * scale;
        ty += 0.001f * scale;

        pos_history.push_back(pos);
        if (pos_history.size() > MAX_SIZE)
        {
            pos_history.pop_front();
        }
    }

    const std::deque<vec2>& getPosHistory() const
    {
        return pos_history;
    }

    void reset()
    {
        pos_history.clear();

        // new seed
        perlin = Perlin(4, randInt());

        // reset position
        tx = 0.0f;
        ty = 10000.0f;
        pos.x = getWindowWidth() / 2.0f;
        pos.y = getWindowHeight() / 2.0f;
    }
};

#endif //CINDER_NATURE_OF_CODE_PERLINWALKER_H
