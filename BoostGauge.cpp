#include "BoostGauge.h"
#include "Display.h"
#include <CircularBuffer.h>


#define DEBUG_LOG


#define SAMPLE_PIN A0

int reading = 0;
int mapped_reading = 0;
Display display;
uint8_t inc = 1;

// refresh_rate = shown_period / x_points
const int graph_displayed_period = 5 * 1000; // 10 seconds
const int graph_x_count          = 128;       // 128 pixels
uint16_t graph_refresh_rate_ms        = (uint16_t)(graph_displayed_period / graph_x_count);
unsigned long graph_last_draw_time = 0;
int graph_value = 0;


unsigned long label_time = 0;
unsigned long loop_execution = 0;


void setup(void)
{
#ifdef DEBUG_LOG
	Serial.begin(9600);
	Serial.println("Initializing . . .");
	//
	Serial.println("");
	Serial.println("Display");
	//
	Serial.print("period: ");
	Serial.println(graph_displayed_period);
	//
	Serial.print("refresh rate: ");
	Serial.println((uint16_t)(graph_displayed_period / graph_x_count));
#endif

	display.setCaption("boost");

	pinMode(SAMPLE_PIN, INPUT);
}

void loop(void)
{
	//return;

	if (millis() - graph_last_draw_time >= graph_refresh_rate_ms)
	{
#ifdef DEBUG_LOG
		Serial.print("Took: ");
		Serial.println(millis() - graph_last_draw_time);
		loop_execution = millis();
#endif


		// Read analog pin
		reading = analogRead(SAMPLE_PIN);

		display.addValue(reading, 0, 900);

		//
		display.printValue(graph_value);
		//
		graph_last_draw_time = millis();

#ifdef DEBUG_LOG
		Serial.println("");
		Serial.println("Loop");
		Serial.print("execution time: ");
		Serial.println(millis() - loop_execution);
#endif
	}



	//	// Show numeric value
	//	if (millis() - label_time >= 250)
	//	{
	//		display.printValue(mapped_reading);
	//		label_time = millis();
	//	}
	//
	//
	//	// Draw graph
	//	if (millis() - graph_time >= 30)
	//	{
	//		// Add to circular buffer
	//		buffer.push(mapped_reading);
	//
	//		for (i = 0; i < buffer.size(); i++)
	//		{
	//			display.draw(&i, buffer[i]);
	//		}
	//
	//
	//		// Read analog pin
	//		reading = analogRead(SAMPLE_PIN);
	//		mapped_reading = map(reading, 0, 1023, 0, 32);
	//
	//		graph_time = millis();
	//	}





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
}
