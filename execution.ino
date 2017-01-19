
#include "Arduino.h"
# define EXECUTE 1
/* This file decides which file is executed
/* 1: simple tempometer
 * 2: humidity sensor
 * 3: proba (always different, temporary file) now: working scope
 */

/*
void setup()
{
	Serial.begin(9600);
	pinMode(7,OUTPUT);
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
}

void loop()
{
	if (Serial.available() > 0)
	{
		// MUST BE HERE TO POP UP possibilities
	    digitalWrite(7,HIGH);
		digitalWrite(8,LOW);
		analogWrite(9,250); // for small fan: min value: 245
	}
}
*/
