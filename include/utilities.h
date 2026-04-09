#ifndef CINDER_NATURE_OF_CODE_UTILITIES
#define CINDER_NATURE_OF_CODE_UTILITIES

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"

namespace util
{
    // Save a screenshot of the current window surface
    inline void saveScreenshot(ci::app::App* app)
    {
        ci::fs::path savePath = app->getSaveFilePath(ci::fs::path(), {"png", "jpg"});
        if (!savePath.empty())
        {
            ci::writeImage(savePath, ci::app::copyWindowSurface());
        }
    }
}

#endif // CINDER_NATURE_OF_CODE_UTILITIES
