#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "../include/WeightedWalker.h"
#include "utilities.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class example_0_3 : public App
{
public:
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void keyDown(KeyEvent event) override;
	void update() override;
	void draw() override;

	WeightedWalker walker;
};

void example_0_3::setup()
{
	walker = WeightedWalker({0.2f, 0.2f, 0.2f, 0.4f});
}

void example_0_3::mouseDown(MouseEvent event)
{
	walker.reset();
}

void example_0_3::keyDown(KeyEvent event)
{
	if (event.getChar() == 's' || event.getChar() == 'S')
	{
		util::saveScreenshot(this);
	}
}

void example_0_3::update()
{
	walker.step(3);
}

void example_0_3::draw()
{
	gl::clear(Color(0, 0, 0));
	gl::enableAlphaBlending();
	gl::color(ColorA(1.0f, 1.0f, 1.0f, 0.25f));
	for (const vec2& pos : walker.getPosHistory())
	{
		gl::drawSolidCircle(pos, 1.0f);
	}
}

CINDER_APP(example_0_3, RendererGl)
