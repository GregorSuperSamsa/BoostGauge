#include "Display.h"


#define DEBUG_LOG

Ucglib_SSD1351_18x128x128_HWSPI ucg(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

Display::Display()
{
	ucg.begin(1);
	ucg.clearScreen();
	ucg.setColor(0xFF, 0xBF, 00);
	//
	drawGauge();
}

Display::~Display() {}

void Display::setCaption(char* caption)
{
	ucg.setColor(0, 0x00, 0x00, 0x00);
	//
	ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
	ucg.setFont(ucg_font_profont15_mf);
	//
	uint8_t caption_x = 87;
	//uint8_t caption_x = (uint8_t)((ucg.getWidth()/2 - ucg.getStrWidth(caption)) /2);
	uint8_t caption_y = 18 - 3;
	ucg.setPrintPos(caption_x, caption_y);
	ucg.setPrintDir(0);

	ucg.print(caption);



	const char lower_caption[4] = "BAR";
	caption_x = 87;
	//caption_x = (uint8_t)((ucg.getWidth()/2 - ucg.getStrWidth(lower_caption)) / 2);
	caption_y = ucg.getHeight() - 3;
	ucg.setPrintPos(caption_x, caption_y);
	ucg.print(lower_caption);
}

void Display::addValue(int value, int value_min, int value_max)
{

	histogram_value_min = 0;
	histogram_value_max = 100;
	histogram_value = map(value, value_min, value_max, histogram_value_min, histogram_value_max);
	histogram_buffer.push(histogram_value);

	printValue(histogram_value);

	for (histogram_index = 0; histogram_index < histogram_buffer.size(); histogram_index++)
	{
		draw(&histogram_index, histogram_buffer[histogram_index]);
	}

//	for (histogram_index = histogram_buffer.size() - 1; histogram_index >= 0; histogram_index--)
//	{
//		draw(&histogram_index, histogram_buffer[histogram_index]);
//	}

	uint8_t col = 42;
	draw(&col, histogram_buffer.last());
	col++;
	draw(&col, histogram_buffer.last());
	col++;
	draw(&col, histogram_buffer.last());
	col++;
	draw(&col, histogram_buffer.last());
	col++;
	draw(&col, histogram_buffer.last());
	col++;
	draw(&col, histogram_buffer.last());
	col++;
	draw(&col, histogram_buffer.last());
	col++;
	draw(&col, histogram_buffer.last());
	col++;
	draw(&col, histogram_buffer.last());

}

void Display::draw(uint8_t *col, int value)
{
	uint8_t histogram_height = 100;
	uint8_t histogram_y      = 121;


	ucg.setColor(0, 0xFF, 0xBF, 00);

	ucg.drawVLine(*col + 7, histogram_y - value, value);


	ucg.setColor(0, 0, 0, 0);
	ucg.drawVLine(*col + 7, histogram_y - histogram_height, histogram_height - value);

}

void Display::printValue(int value)
{
	return;

#ifdef DEBUG_LOG
	Serial.println("");
	Serial.print("Display::");
	Serial.print(__func__);
	Serial.println("()");
#endif

	sprintf(reading, "%2d", value);

#ifdef DEBUG_LOG
	Serial.println(reading);
#endif


	ucg.setColor(0, 0xFF, 0xBF, 00);
	ucg.setFontMode(UCG_FONT_MODE_SOLID);
	ucg.setFont(ucg_font_inr33_mn);


	uint8_t reading_x = ucg.getWidth() - ucg.getStrWidth(reading) - 2;
	uint8_t reading_y = 33 + 2;
	ucg.setPrintPos(reading_x, reading_y);
	ucg.setPrintDir(0);

	ucg.print(reading);
}

void Display::drawGauge()
{
	// Gauge upper caption box
	uint8_t header_x      = 70;
	uint8_t header_y      = 0;
	uint8_t header_width  = ucg.getWidth();
	uint8_t header_height = 18;
	ucg.drawBox(header_x, header_y, header_width, header_height);
	//ucg.drawTriangle(70, 18, 52, 0, 70, 0);

	// Gauge lower caption box
	uint8_t footer_x       = 70;
	uint8_t footer_y       = 110;
	uint8_t footer_width   = ucg.getWidth();
	uint8_t footer_height = 18;
	ucg.drawBox(footer_x, footer_y, footer_width, footer_height);
	//ucg.drawTriangle(70, 110, 70, 128, 52, 128);


	// Gauge frame
	uint8_t face_x      = 0;
	uint8_t face_y      = 0;
	uint8_t face_width  = ucg.getWidth();
	uint8_t face_height = ucg.getHeight();
	ucg.drawFrame(face_x, face_y, 64, face_height);


//	ucg.drawLine(0, 0, 0, 128);
//	ucg.drawLine(127, 0, 127, 128);
//
//	ucg.drawLine(0, 0, 46, 0);
//	ucg.drawLine(46, 0, 64, 18);
//
//	ucg.drawLine(0, 127, 46, 127);
//	ucg.drawLine(46, 128, 64, 128 - 18);
//
//	ucg.drawLine(64, 18, 64, 128 - 18);

	ucg.drawTriangle(64, 60, 64, 68, 60, 64);
	ucg.drawTriangle(1, 60, 1, 68, 5, 64);


	//	// Bars
	//	ucg.drawTriangle(49, 122,
	//			         60, 122 - 11,
	//					 49, 122 - 11);
	//
	//	ucg.drawBox(49, 122 - 2*11 - 4, 12, 12);
	//	ucg.drawBox(49, 122 - 3*11 - 2*4, 12, 12);
	//	ucg.drawBox(49, 122 - 4*11 - 3*4, 12, 12);
	//	ucg.drawBox(49, 122 - 5*11 - 4*4, 12, 12);
	//	ucg.drawBox(49, 122 - 6*11 - 5*4, 12, 12);





	// Reading
	ucg.setColor(0, 0xFF, 0xBF, 00);
	ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
	ucg.setFont(ucg_font_profont29_mr);

	//uint8_t reading_x = 5;
	uint8_t reading_x = 58;
	uint8_t reading_y = 55;
	ucg.setPrintPos(reading_x, reading_y);
	ucg.setPrintDir(0);
	ucg.print(" 0.5");

	ucg.setFont(ucg_font_profont12_8f);

	uint8_t peak_x = 93;
	uint8_t peak_y = 40 + 40;
	ucg.setPrintPos(peak_x, peak_y);
	ucg.print("PEAK");

	ucg.setFont(ucg_font_profont15_8f);
	peak_x = 90;
	peak_y = 55 + 40;
	ucg.setPrintPos(peak_x, peak_y);

	ucg.print(" 0.5");

	//	// Gauge upper caption box
	//	uint8_t header_x      = 0;
	//	uint8_t header_y      = 0;
	//	uint8_t header_width  = ucg.getWidth();
	//	uint8_t header_height = 18;
	//	ucg.drawBox(header_x, header_y, header_width, header_height);
	//
	//	// Gauge lower caption box
	//	uint8_t footer_x       = 0;
	//	uint8_t footer_y       = 110;
	//	uint8_t footer_width   = ucg.getWidth();
	//	uint8_t footer_height = ucg.getHeight() - gauge_caption_y;
	//	ucg.drawBox(footer_x, footer_y, footer_width, footer_height);
	//
	//
	//	// Gauge frame
	//	uint8_t face_x      = 0;
	//	uint8_t face_y      = header_height;
	//	uint8_t face_width  = ucg.getWidth();
	//	uint8_t face_height = ucg.getHeight() - (header_height + footer_height);
	//	ucg.drawFrame(face_x, face_y, face_width, face_height);
	//
	//
	//	// Reading
	//	ucg.setColor(0, 0xFF, 0xBF, 00);
	//	ucg.setFontMode(UCG_FONT_MODE_SOLID);
	//	ucg.setFont(ucg_font_profont29_mr);
	//
	//	uint8_t reading_x = 5;
	//	uint8_t reading_y = 55;
	//	ucg.setPrintPos(reading_x, reading_y);
	//	ucg.setPrintDir(0);
	//	ucg.print("-0.5");
	//
	//
	//	ucg.setFont(ucg_font_profont12_8f);
	//
	//	uint8_t peak_x = 93;
	//	uint8_t peak_y = 40;
	//	ucg.setPrintPos(peak_x, peak_y);
	//	ucg.print("PEAK");
	//
	//	ucg.setFont(ucg_font_profont15_8f);
	//	peak_x = 90;
	//	peak_y = 55;
	//	ucg.setPrintPos(peak_x, peak_y);
	//
	//	ucg.print("-0.5");
}

void Display::clearHistogram()
{
	//
}


