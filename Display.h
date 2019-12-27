#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <Ucglib.h>

class Display
{
public:
	Display();
	virtual ~Display();

	void draw(uint8_t *col, int value);
	void clearHistogram();
	void printValue(int value);
	void setCaption(char* caption);

private:
	uint8_t graph_height = 96;
	uint8_t graph_y      = 106;
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

	char reading[5];

private:
	void drawFrames();

};


#endif /* DISPLAY_H_ */
