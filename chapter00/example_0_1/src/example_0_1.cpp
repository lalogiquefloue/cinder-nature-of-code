#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "../include/Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class example_0_2 : public App
{
public:
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void keyDown(KeyEvent event) override;
	void update() override;
	void draw() override;

	Walker walker;
};

void example_0_2::setup()
{
	walker = Walker();
}

void example_0_2::mouseDown(MouseEvent event)
{
	walker.reset();
}

void example_0_2::keyDown(KeyEvent event)
{
	if (event.getChar() == 's' || event.getChar() == 'S')
	{
		fs::path savePath = getSaveFilePath(fs::path(), {"png", "jpg"});
		if (!savePath.empty())
		{
			writeImage(savePath, copyWindowSurface());
		}
	}
}

void example_0_2::update()
{
	walker.step(3);
}

void example_0_2::draw()
{
	gl::clear(Color(0, 0, 0));
	gl::enableAlphaBlending();
	gl::color(ColorA(1.0f, 1.0f, 1.0f, 0.25f));
	for (const vec2& pos : walker.getPosHistory())
	{
		gl::drawSolidCircle(pos, 1.0f);
	}
}

CINDER_APP(example_0_2, RendererGl)
