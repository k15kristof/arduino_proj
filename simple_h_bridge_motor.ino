#if (EXECUTE==6)
#include "Arduino.h"

//Keyboard Controls:
//
// 1 -Motor 1 Left
// 2 -Motor 1 Stop
// 3 -Motor 1 Right

// Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.

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
			int inByte = Serial.read();

			switch (inByte)
			{
			case '1':
				digitalWrite(8,LOW);
				digitalWrite(7,HIGH);
				analogWrite(9,245); // for small fan: min value: 245
				Serial.println("slower");
				Serial.println("------------------------------------------\n");
				break;
			case '2':
				digitalWrite(8,LOW);
				digitalWrite(7,HIGH);
				analogWrite(9,255); // for small fan: min value: 245
				Serial.println("faster");
				Serial.println("------------------------------------------\n");
				break;
			case '3':
				digitalWrite(8,HIGH);
				digitalWrite(7,LOW);
				analogWrite(9,245); // for small fan: min value: 245
				Serial.println("other_direction slower");
				Serial.println("------------------------------------------\n");
				break;
			case '4':
				digitalWrite(8,HIGH);
				digitalWrite(7,LOW);
				analogWrite(9,255); // for small fan: min value: 245
				Serial.println("other_direction faster");
				Serial.println("------------------------------------------\n");
				break;
			default:
				digitalWrite(8,LOW);
				digitalWrite(7,HIGH);
				analogWrite(9,0); // for small fan: min value: 245
			}
		}

}

#endif
