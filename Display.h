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
	uint8_t frame_caption_x;
	uint8_t frame_caption_y;
	uint8_t frame_caption_width;
	uint8_t frame_caption_height;
	//
	uint8_t frame_measurement_x;
	uint8_t frame_measurement_y;
	uint8_t frame_measurement_width;
	uint8_t frame_measurement_height;
	//
	char reading[5];
	//
	CircularBuffer<int, 64> histogram_buffer;
	using index_t = decltype(histogram_buffer)::index_t;
	index_t histogram_index;
	int histogram_value = 0;
	//
	int histogram_value_min = 0;
	int histogram_value_max = 0;

private:
	void drawFrames();

};


#endif /* DISPLAY_H_ */
