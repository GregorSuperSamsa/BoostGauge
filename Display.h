#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <Ucglib.h>
#include <CircularBuffer.h>

class Display
{
public:
	Display();
	virtual ~Display();

	void draw(uint8_t *col, int value);
	void clearHistogram();
	void printValue(int value);
	void setCaption(char* caption);
	void addValue(int value, int value_min, int value_max);

private:
	//
	uint8_t gauge_caption_x;
	uint8_t gauge_caption_y;
	uint8_t gauge_caption_width;
	uint8_t gauge_caption_height;
	//
	uint8_t gauge_frame_x;
	uint8_t gauge_frame_y;
	uint8_t gauge_frame_width;
	uint8_t gauge_frame_height;
	//
	char reading[5];
	//
	//CircularBuffer<int, 120 > histogram_buffer;
	CircularBuffer<int, 39> histogram_buffer;
	using index_t = decltype(histogram_buffer)::index_t;
	index_t histogram_index;
	int histogram_value = 0;
	//
	int histogram_value_min = 0;
	int histogram_value_max = 50;

private:
	void drawGauge();

};


#endif /* DISPLAY_H_ */
