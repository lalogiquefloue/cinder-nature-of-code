#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "utilities.h"

#define TOTAL_COUNT 20

using namespace ci;
using namespace ci::app;
using namespace std;

class example_0_5 : public App
{
public:
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void update() override;
	int acceptRejectDistribution(int);
	void draw() override;
	void keyDown(KeyEvent event) override;
	std::vector<int> random_counts;
};

void example_0_5::setup()
{
	random_counts.assign(TOTAL_COUNT, 0);
}

void example_0_5::mouseDown(MouseEvent event)
{
	setup();
}

void example_0_5::update()
{
	int idx = example_0_5::acceptRejectDistribution(TOTAL_COUNT);
	random_counts[idx]++;
}

int example_0_5::acceptRejectDistribution(int range)
{
	while (true)
	{
		int r1 = randInt(range);
		int r2 = randInt(range);
		if (r2 < r1) return r1;
	}
}

void example_0_5::draw()
{
	gl::clear(Color(0, 0, 0));
	float bin_width = (float)getWindowWidth() / TOTAL_COUNT;

	for (int i = 0; i < TOTAL_COUNT; i++)
	{
		int curr_bin_height = random_counts[i];
		Rectf rect(i * bin_width, getWindowHeight(), (i + 1) * bin_width, getWindowHeight() - curr_bin_height);
		gl::color(1.0f, 1.0f, 1.0f);
		gl::drawSolidRect(rect);

		gl::color(Color(0.0f, 0.0f, 0.0f));
		gl::drawStrokedRect(rect);
	}
}

void example_0_5::keyDown(KeyEvent event)
{
	if (event.getChar() == 's' || event.getChar() == 'S')
	{
		util::saveScreenshot(this);
	}
}

CINDER_APP(example_0_5, RendererGl)
