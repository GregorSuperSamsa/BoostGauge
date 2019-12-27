#include "Display.h"

Ucglib_SSD1351_18x128x128_HWSPI ucg(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

Display::Display()
{
	ucg.begin(0);
	ucg.clearScreen();
	ucg.setColor(0xFF, 0xBF, 00);
	//
	drawFrames();
}

Display::~Display() {}

void Display::setCaption(char* caption)
{
	ucg.setPrintDir(0);
	ucg.setFont(ucg_font_helvR12_tr);

	uint8_t caption_x = (uint8_t)((ucg.getWidth() - ucg.getStrWidth(caption)) /2);
	uint8_t caption_y = ucg.getHeight() - 3;
	ucg.setPrintPos(caption_x, caption_y);

	ucg.print(caption);
}

void Display::draw(uint8_t *col, int value)
{
	ucg.setColor(0, 0, 0);
	ucg.drawVLine(*col + 2, graph_y - graph_height, graph_height - value);

	ucg.setColor(0, 0xFF, 0xBF, 00);
	ucg.drawVLine(*col + 2, graph_y - value, value);

}

void Display::printValue(int value)
{
	sprintf(reading, "%2d", value);

	ucg.setColor(0, 0xFF, 0xBF, 00);
	ucg.setFont(ucg_font_inr33_mn);
	ucg.setFontMode(UCG_FONT_MODE_SOLID);

	ucg.setPrintDir(0);

	uint8_t reading_x = 74;
	uint8_t reading_y = 54;
	ucg.setPrintPos(reading_x, reading_y);
	ucg.print(reading);
}

void Display::drawFrames()
{
	// Caption frame
	frame_caption_x      = 0;
	frame_caption_y      = 110;
	frame_caption_width  = ucg.getWidth();
	frame_caption_height = ucg.getHeight() - frame_caption_y;
	ucg.drawFrame(frame_caption_x, frame_caption_y, frame_caption_width, frame_caption_height);

	// Measurement frame
	frame_measurement_x      = 0;
	frame_measurement_y      = 0;
	frame_measurement_width  = frame_caption_width;
	frame_measurement_height = frame_caption_y - 2;
	ucg.drawFrame(frame_measurement_x, frame_measurement_y, frame_measurement_width, frame_measurement_height);
}

void Display::clearHistogram()
{
	//
}


