#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "../include/SteeredWalker.h"
#include "utilities.h"

#define BIAS_RATIO 0.2f // should be lower than 0.25f

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

	SteeredWalker mWalker;
	ivec2 mMousePos;
};

void exercise_0_3::setup()
{
	mWalker = SteeredWalker();
}

void exercise_0_3::update()
{
	vec2 dir = (vec2)mMousePos - mWalker.pos;
	float len = glm::length(dir);
	vec2 unitVector = dir / len;

	float up = 0.25f;
	float down = 0.25f;
	float left = 0.25f;
	float right = 0.25f;

	if (len > 0)
	{
		up += BIAS_RATIO * unitVector.y;
		down -= BIAS_RATIO * unitVector.y;
		right += BIAS_RATIO * unitVector.x;
		left -= BIAS_RATIO * unitVector.x;
	}

	mWalker.mWeights = {up, down, left, right};
	mWalker.step(3);
}

void exercise_0_3::draw()
{
	gl::clear(Color(0, 0, 0));

	gl::color(Color(1, 0, 0));
	gl::drawSolidCircle(mMousePos, 3.0f);

	gl::enableAlphaBlending();
	gl::color(ColorA(1.0f, 1.0f, 1.0f, 0.25f));
	for (const vec2& pos : mWalker.getPosHistory())
	{
		gl::drawSolidCircle(pos, 1.0f);
	}
}

void exercise_0_3::mouseMove(MouseEvent event)
{
	mMousePos = event.getPos();
}

void exercise_0_3::mouseDown(MouseEvent event)
{
	mWalker.reset();
}

void exercise_0_3::keyDown(KeyEvent event)
{
	if (event.getChar() == 's' || event.getChar() == 'S')
	{
		util::saveScreenshot(this);
	}
}

CINDER_APP(exercise_0_3, RendererGl)
