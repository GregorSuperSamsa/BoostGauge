#include "BoostGauge.h"
#include "Display.h"
#include <CircularBuffer.h>


#define DEBUG_LOG
#define SAMPLE_PIN A0


int analog_reading = 0;
int mapped_reading = 0;
Display display;


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

	display.setCaption("BOOST");

	pinMode(SAMPLE_PIN, INPUT);
}

void loop(void)
{
	if (millis() - graph_last_draw_time >= graph_refresh_rate_ms)
	{
#ifdef DEBUG_LOG
		Serial.println("");
		Serial.print("Took: ");
		Serial.println(millis() - graph_last_draw_time);
		loop_execution = millis();
#endif

		// Read analog pin
		analog_reading = analogRead(SAMPLE_PIN);

#ifdef DEBUG_LOG
		Serial.print("analog_reading = ");
		Serial.println(analog_reading);
#endif

		//
		display.addValue(analog_reading, 0, 900);
		//
		graph_last_draw_time = millis();

#ifdef DEBUG_LOG
		Serial.println("");
		Serial.print("Loop execution time: ");
		Serial.println(millis() - loop_execution);
#endif
	}
}
