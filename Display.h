#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <Ucglib.h>

class Display
{
public:
	Display();
	//Display(Ucglib_SSD1351_18x128x128_HWSPI *d);
	virtual ~Display();

private:
	//Ucglib_SSD1351_18x128x128_HWSPI *d;
	//uint8_t map[128];
};


#endif /* DISPLAY_H_ */
