#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "../include/PerlinWalker.h"
#include "utilities.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class example_0_6 : public App
{
public:
	void mouseDown(MouseEvent event) override;
	void keyDown(KeyEvent event) override;
	void update() override;
	void draw() override;

	PerlinWalker walker;
};


void example_0_6::mouseDown(MouseEvent event)
{
	walker.reset();
}

void example_0_6::keyDown(KeyEvent event)
{
	if (event.getChar() == 's' || event.getChar() == 'S')
	{
		util::saveScreenshot(this);
	}
}

void example_0_6::update()
{
	walker.step(5);
}

void example_0_6::draw()
{
	gl::clear(Color(0, 0, 0));
	gl::enableAlphaBlending();

	const auto& pos_history = walker.getPosHistory();
	float historySize = static_cast<float>(pos_history.size());

	for (int i = 0; i < historySize; i++)
	{
		float alpha = (i / historySize) * 0.5f;
		gl::color(ColorA(1.0f, 1.0f, 1.0f, alpha));
		gl::drawSolidCircle(pos_history[i], 7.5f);
	}
}

CINDER_APP(example_0_6, RendererGl)
