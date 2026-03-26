#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#define TOTAL_COUNT 20

using namespace ci;
using namespace ci::app;
using namespace std;

class example_0_2 : public App
{
public:
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void update() override;
	void draw() override;
	std::vector<int> random_counts;
};

void example_0_2::setup()
{
	random_counts.assign(TOTAL_COUNT, 0);
}

void example_0_2::mouseDown(MouseEvent event)
{
	setup();
}

void example_0_2::update()
{
	int idx = randInt(TOTAL_COUNT);
	random_counts[idx]++;
}

void example_0_2::draw()
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

CINDER_APP(example_0_2, RendererGl)
