#include "BoostGauge.h"
#include "Display.h"
#include <CircularBuffer.h>



#define SAMPLE_PIN A0
CircularBuffer<int, 128> buffer;
int reading = 0;
int mapped_reading = 0;
Display display;
uint8_t inc = 1;


using index_t = decltype(buffer)::index_t;
index_t i;

unsigned long label_time = 0;
unsigned long graph_time = 0;

void setup(void)
{
	//	Serial.begin(9600);
	//	Serial.println("Initializing . . .");
	pinMode(SAMPLE_PIN, INPUT);
}

void loop(void)
{

	// Test
	//	if (reading >= 32) inc = 0;
	//	else if (reading <= 0) inc = 1;
	//
	//	if (inc == 1) reading++;
	//	else reading--;
	//	mapped_reading = reading;


	//	// Read analog pin
	//	reading = analogRead(SAMPLE_PIN);
	//	mapped_reading = map(reading, 0, 1023, 0, 32);
	//
	//
	//	// Add to circular buffer
	//	buffer.push(mapped_reading);
	//

	// Show numeric value
	if (millis() - label_time >= 250)
	{
		display.printValue(mapped_reading);
		label_time = millis();
	}


	// Draw graph
	if (millis() - graph_time >= 30)
	{
		// Add to circular buffer
		buffer.push(mapped_reading);

		for (i = 0; i < buffer.size(); i++)
		{
			display.draw(&i, buffer[i]);
		}
		graph_time = millis();

		// Read analog pin
		reading = analogRead(SAMPLE_PIN);
		mapped_reading = map(reading, 0, 1023, 0, 32);
	}
}
