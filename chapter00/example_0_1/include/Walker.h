#ifndef CINDER_NATURE_OF_CODE_WALKER_H
#define CINDER_NATURE_OF_CODE_WALKER_H

#include "cinder/Rand.h"
#include "cinder/app/AppBase.h"

class Walker
{
public:
    glm::vec2 pos;
    std::vector<glm::vec2> pos_history;

    Walker()
    {
        pos.x = cinder::app::getWindowWidth() / 2.0f;
        pos.y = cinder::app::getWindowHeight() / 2.0f;
    };

    void step(float scale = 1.0f)
    {
        switch (cinder::randInt(4))
        {
        case 0:
            pos.x += 1.0f * scale;
            break;
        case 1:
            pos.x -= 1.0f * scale;
            break;
        case 2:
            pos.y += 1.0f * scale;
            break;
        case 3:
            pos.y -= 1.0f * scale;
            break;
        default:
            break;
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

#endif //CINDER_NATURE_OF_CODE_WALKER_H
