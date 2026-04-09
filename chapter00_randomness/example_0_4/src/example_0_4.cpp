#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "utilities.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class example_0_4 : public App
{
public:
	void update() override;
	void draw() override;
	void keyDown(KeyEvent event) override;

	std::vector<vec2> mPoints;
};

void example_0_4::update()
{
	float stdDev = getWindowWidth() / 6.0f;
	float mean = getWindowWidth() / 2.0f;

	float x = Rand::randGaussian() * stdDev + mean;
	float y = getWindowHeight() / 2.0f;

	mPoints.push_back(vec2(x, y));
}

void example_0_4::draw()
{
	gl::clear(Color(0, 0, 0));

	gl::enableAlphaBlending();
	gl::color(ColorA(1.0f, 1.0f, 1.0f, 0.01f));

	for (auto point : mPoints)
	{
		gl::drawSolidCircle(point, 25.0f);
	}
}

void example_0_4::keyDown(KeyEvent event)
{
	if (event.getChar() == 's' || event.getChar() == 'S')
	{
		util::saveScreenshot(this);
	}
}

CINDER_APP(example_0_4, RendererGl)
