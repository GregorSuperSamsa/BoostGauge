#include "Display.h"

Ucglib_SSD1351_18x128x128_HWSPI ucg(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

Display::Display()
{
	ucg.begin(0);
	ucg.clearScreen();

	ucg.setFont(ucg_font_courB12_mr);
	ucg.setColor(0xFF, 0xBF, 00);
	ucg.setPrintPos(110,10);
	ucg.setPrintDir(1);
	ucg.print("BOOST");
}

Display::~Display() {}

void Display::draw(uint8_t *col, int value)
{
	ucg.setColor(0, 0xFF, 0xBF, 00);
	ucg.drawHLine(0, *col, value);

	ucg.setColor(0, 0, 0);
	ucg.drawHLine(value, *col, 32-value);
}

void Display::printValue(int value)
{
	sprintf(reading, "%3d", value);


	ucg.setColor(0, 0xFF, 0xBF, 00);
	ucg.setPrintPos(50,10);
	ucg.setPrintDir(1);
	ucg.print(reading);
}

void Display::clearHistogram()
{

	//ucg.setColor(0, 0, 0);
	//ucg.drawBox(0, 0, 32, 128);
	//ucg.clearScreen();
	//ucg.setColor(0, 0xFF, 0xBF, 00);
	//ucg.clearScreen();
}
