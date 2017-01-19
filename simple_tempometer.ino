# if (EXECUTE==1)
#include "Arduino.h"
/*-----( Import needed libraries )-----*/
#include <OneWire.h>
#include <DallasTemperature.h>

/*-----( Declare Constants )-----*/
#define ONE_WIRE_BUS 3 /*-(Connect to Pin 3 )-*/

/*-----( Declare objects )-----*/
/* Set up a oneWire instance to communicate with any OneWire device*/
OneWire ourWire(ONE_WIRE_BUS);

/* Tell Dallas Temperature Library to use oneWire Library */
DallasTemperature sensors(&ourWire);

/*-----( Declare Variables )-----*/


void setup() /*----( SETUP: RUNS ONCE )----*/
{
/*-(start serial port to see results )-*/
Serial.begin(9600);
delay(10);

/*-( Start up the DallasTemperature library )-*/
sensors.begin();
}/*--(end setup )---*/


void loop() /*----( LOOP: RUNS CONSTANTLY )----*/
{
Serial.println();
sensors.requestTemperatures(); // Send the command to get temperatures

Serial.print(sensors.getTempCByIndex(0));
delay(50);
}/* --(end main loop )-- */

/* ( THE END ) */
#endif
