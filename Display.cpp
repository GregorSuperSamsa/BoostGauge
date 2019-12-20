#include "Display.h"

Ucglib_SSD1351_18x128x128_HWSPI ucg(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

Display::Display()
{

	ucg.begin(1);
	ucg.clearScreen();



	ucg.setFont(ucg_font_5x7_mr);
	ucg.setColor(0xFF, 0xBF, 00);
	ucg.setPrintPos(25,45);
	ucg.setPrintDir(0);
	ucg.print("BOOST:");

	ucg.setColor(0, 0xFF, 0xBF, 00);
	ucg.drawHLine(0, 0, 45);
	ucg.drawHLine(0, 1, 45);
	ucg.drawHLine(0, 2, 45);
	ucg.drawHLine(0, 3, 45);
	ucg.drawHLine(0, 4, 45);
}



Display::~Display()
{

}


//
///*
//
//  GraphicsTest.ino
//
//  Generate some example graphics
//
//  Universal uC Color Graphics Library
//
//  Copyright (c) 2014, olikraus@gmail.com
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification,
//  are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice, this list
//    of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above copyright notice, this
//    list of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
//  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
//  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
//  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
//  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*/
//
//#include <SPI.h>
//#include "Ucglib.h"
//
//Ucglib_SSD1351_18x128x128_HWSPI ucg(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);
//void text(void)
//{
//  ucg_int_t x, y, w, h, i;
//  unsigned long m;
//
//  ucg.setColor(0, 80, 40, 0);
//  ucg.setColor(1, 60, 0, 40);
//  ucg.setColor(2, 20, 0, 20);
//  ucg.setColor(3, 60, 0, 0);
//  ucg.drawGradientBox(0, 0, ucg.getWidth(), ucg.getHeight());
//
//  ucg.setColor(255, 255, 255);
//  ucg.setPrintPos(2,18);
//  ucg.setPrintDir(0);
//  ucg.print("Text");
//
//  m = millis() + T;
//  i = 0;
//  while( millis() < m )
//  {
//    ucg.setColor(lcg_rnd() & 31, (lcg_rnd()&127)+127, (lcg_rnd()&127)+64);
//    w = 40;
//    h = 22;
//    x = (lcg_rnd()*(ucg.getWidth()-w))>>8;
//    y = (lcg_rnd()*(ucg.getHeight()-h))>>8;
//
//    ucg.setPrintPos(x,y+h);
//    ucg.setPrintDir((i>>2)&3);
//    i++;
//    ucg.print("Ucglib");
//  }
//  ucg.setPrintDir(0);
//
//}
//
//void fonts(void)
//{
//  ucg_int_t d = 5;
//  ucg.setColor(0, 0, 40, 80);
//  ucg.setColor(1, 150, 0, 200);
//  ucg.setColor(2, 60, 0, 40);
//  ucg.setColor(3, 0, 160, 160);
//
//  ucg.drawGradientBox(0, 0, ucg.getWidth(), ucg.getHeight());
//
//  ucg.setColor(255, 255, 255);
//  ucg.setPrintDir(0);
//  ucg.setPrintPos(2,18);
//  ucg.print("Fonts");
//
//  ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
//
//  ucg.setColor(255, 200, 170);
//  ucg.setFont(ucg_font_helvB08_hr);
//  ucg.setPrintPos(2,30+d);
//  ucg.print("ABC abc 123");
//  ucg.setFont(ucg_font_helvB10_hr);
//  ucg.setPrintPos(2,45+d);
//  ucg.print("ABC abc 123");
//  ucg.setFont(ucg_font_helvB12_hr);
//  //ucg.setPrintPos(2,62+d);
//  //ucg.print("ABC abc 123");
//  ucg.drawString(2,62+d, 0, "ABC abc 123"); // test drawString
//
//  ucg.setFontMode(UCG_FONT_MODE_SOLID);
//
//  ucg.setColor(255, 200, 170);
//  ucg.setColor(1, 0, 100, 120);		// background color in solid mode
//  ucg.setFont(ucg_font_helvB08_hr);
//  ucg.setPrintPos(2,75+30+d);
//  ucg.print("ABC abc 123");
//  ucg.setFont(ucg_font_helvB10_hr);
//  ucg.setPrintPos(2,75+45+d);
//  ucg.print("ABC abc 123");
//  ucg.setFont(ucg_font_helvB12_hr);
//  ucg.setPrintPos(2,75+62+d);
//  ucg.print("ABC abc 123");
//
//  ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
//
//  /* big fonts removed, some trouble with the Arduino IDE */
//  /*
//  ucg.setFont(ucg_font_helvB14_hr);
//  ucg.setPrintPos(2,79+d);
//  ucg.print("ABC abc 123");
//  ucg.setFont(ucg_font_helvB18_hr);
//  ucg.setPrintPos(2,79+22+d);
//  ucg.print("ABC abc 123");
//  */
//
//  ucg.setFont(ucg_font_ncenR14_hr);
//  DLY();
//}
//
//void clip(void)
//{
//  ucg.setColor(0, 0x00, 0xd1, 0x5e);		// dark green
//  ucg.setColor(1, 0xff, 0xf7, 0x61);		// yellow
//  ucg.setColor(2, 0xd1, 0xc7, 0x00);			// dark yellow
//  ucg.setColor(3, 0x61, 0xff, 0xa8);		// green
//
//  ucg.drawGradientBox(0, 0, ucg.getWidth(), ucg.getHeight());
//
//  ucg.setColor(255, 255, 255);
//  ucg.setPrintPos(2,18);
//  ucg.setPrintDir(0);
//  ucg.print("ClipRange");
//
//  ucg.setColor(0xd1, 0x00, 0x073);
//
//  ucg.setFont(ucg_font_helvB18_hr);
//
//  ucg.setPrintPos(25,45);
//  ucg.setPrintDir(0);
//  ucg.print("Ucg");
//  ucg.setPrintDir(1);
//  ucg.print("Ucg");
//  ucg.setPrintDir(2);
//  ucg.print("Ucg");
//  ucg.setPrintDir(3);
//  ucg.print("Ucg");
//
//
//  ucg.setMaxClipRange();
//  ucg.setColor(0xff, 0xff, 0xff);
//  ucg.drawFrame(20-1,30-1,15+2,20+2);
//  ucg.setClipRange(20, 30, 15, 20);
//  ucg.setColor(0xff, 0x61, 0x0b8);
//  ucg.setPrintPos(25,45);
//  ucg.setPrintDir(0);
//  ucg.print("Ucg");
//  ucg.setPrintDir(1);
//  ucg.print("Ucg");
//  ucg.setPrintDir(2);
//  ucg.print("Ucg");
//  ucg.setPrintDir(3);
//  ucg.print("Ucg");
//
//
//  ucg.setMaxClipRange();
//  ucg.setColor(0xff, 0xff, 0xff);
//  ucg.drawFrame(60-1,35-1,25+2,18+2);
//  ucg.setClipRange(60, 35, 25, 18);
//  ucg.setColor(0xff, 0x61, 0x0b8);
//  ucg.setPrintPos(25,45);
//  ucg.setPrintDir(0);
//  ucg.print("Ucg");
//  ucg.setPrintDir(1);
//  ucg.print("Ucg");
//  ucg.setPrintDir(2);
//  ucg.print("Ucg");
//  ucg.setPrintDir(3);
//  ucg.print("Ucg");
//
//  ucg.setMaxClipRange();
//  ucg.setColor(0xff, 0xff, 0xff);
//  ucg.drawFrame(7-1,58-1,90+2,4+2);
//  ucg.setClipRange(7, 58, 90, 4);
//  ucg.setColor(0xff, 0x61, 0x0b8);
//  ucg.setPrintPos(25,45);
//  ucg.setPrintDir(0);
//  ucg.print("Ucg");
//  ucg.setPrintDir(1);
//  ucg.print("Ucg");
//  ucg.setPrintDir(2);
//  ucg.print("Ucg");
//  ucg.setPrintDir(3);
//  ucg.print("Ucg");
//
//  ucg.setFont(ucg_font_ncenR14_hr);
//  ucg.setMaxClipRange();
//  DLY();
//
//}
//
//void setup(void)
//{
//  delay(1000);
//  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
//  ucg.setFont(ucg_font_ncenR14_hr);
//  ucg.clearScreen();
//}
//
//uint8_t r = 0;
//void loop(void)
//{
//}
