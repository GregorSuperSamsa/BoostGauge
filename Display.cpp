#include "Display.h"


#define DEBUG_LOG

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

void Display::addValue(int value, int value_min, int value_max)
{
	histogram_value = map(value, value_min, value_max, histogram_value_min, histogram_value_max);
	histogram_buffer.push(histogram_value);

//	for (i = 0; i < buffer.size(); i++)
//			{
//				display.draw(&i, buffer[i]);
//			}

}

void Display::draw(uint8_t *col, int value)
{
	uint8_t histogram_height = frame_measurement_height - 2;
	uint8_t histogram_y      = (frame_measurement_height - frame_measurement_x) / 2;

#ifdef DEBUG_LOG
	Serial.print("histogram y: ");
	Serial.println(histogram_y);
#endif


	//if (value > 0)
	{
		ucg.setColor(0, 0xFF, 0xBF, 00);
		ucg.drawVLine(*col + 2, histogram_y, value);
	}

	//	ucg.setColor(0, 0, 0);
	//	ucg.drawVLine(*col + 2, histogram_y - histogram_height, histogram_height - value);


}

void Display::printValue(int value)
{
	return;

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


