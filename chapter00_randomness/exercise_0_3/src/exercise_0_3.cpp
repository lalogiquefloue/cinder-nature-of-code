#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "../include/SteeredWalker.h"
#include "utilities.h"

#define BIAS 0.15f

using namespace ci;
using namespace ci::app;
using namespace std;

class exercise_0_3 : public App
{
public:
	void setup() override;
	void update() override;
	void draw() override;

	void mouseMove(MouseEvent event) override;
	void mouseDown(MouseEvent event) override;
	void keyDown(KeyEvent event) override;

	SteeredWalker walker;
	ivec2 mousePos;
};

void exercise_0_3::setup()
{
	walker = SteeredWalker();
}

void exercise_0_3::update()
{
	vec2 dir = (vec2)mousePos - walker.pos;
	float len = glm::length(dir);

	float up = 0.25f;
	float down = 0.25f;
	float left = 0.25f;
	float right = 0.25f;

	if (len > 0) {
		if (dir.x > 0) {
			right += BIAS;
			left  -= BIAS;
		} else {
			left  += BIAS;
			right -= BIAS;
		}

		if (dir.y > 0) {
			up   += BIAS;
			down -= BIAS;
		} else {
			down += BIAS;
			up   -= BIAS;
		}
	}

	walker.mWeights = {up, down, left, right};
	walker.step(3);
}

void exercise_0_3::draw()
{
	gl::clear(Color(0, 0, 0));

	gl::color(Color(1,0,0));
	gl::drawSolidCircle(mousePos, 3.0f);

	gl::enableAlphaBlending();
	gl::color(ColorA(1.0f, 1.0f, 1.0f, 0.25f));
	for (const vec2& pos : walker.getPosHistory())
	{
		gl::drawSolidCircle(pos, 1.0f);
	}
}

void exercise_0_3::mouseMove(MouseEvent event)
{
	mousePos = event.getPos();
}

void exercise_0_3::mouseDown(MouseEvent event)
{
	walker.reset();
}

void exercise_0_3::keyDown(KeyEvent event)
{
	if (event.getChar() == 's' || event.getChar() == 'S')
	{
		util::saveScreenshot(this);
	}
}

CINDER_APP(exercise_0_3, RendererGl)
