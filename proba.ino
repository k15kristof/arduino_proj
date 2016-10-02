#if (EXECUTE==3)
#include "Arduino.h"
/*

SimPlot Demo Arduino Sketch.
Generates and sends out 4 channels of data to be plotted using SimPlot.

*/

/* prototypes */
void plot(int data1, int data2, int data3, int data4);
/*******************************************************/

void setup()
{
 Serial.begin(9600);

}

int buffer_r[20];
float deltaAngle = 3.14/51; //Arbitrary angle increment size
float angle = 0;
int amplitude = 100;

void loop()
{

 int data1;
 int data2;
 int data3;
 int data4;

 //Generating data that will be plotted
 data1 = amplitude * abs(sin(angle));
 data2 = amplitude * cos(angle);

 data3 = (amplitude/2) * sin(angle);
 data4 = (amplitude/2) * cos(angle);

 angle = angle + deltaAngle;

 plot(data1,data2,data3,data4);

 delay(100); //Need some delay else the program gets swamped with data
}

void plot(int data1, int data2, int data3, int data4)
 {
  int pktSize;

  buffer_r[0] = 0xCDAB;             //SimPlot packet header. Indicates start of data packet
  buffer_r[1] = 4*sizeof(int);      //Size of data in bytes. Does not include the header and size fields
  buffer_r[2] = data1;
  buffer_r[3] = data2;
  buffer_r[4] = data3;
  buffer_r[5] = data4;

  pktSize = 2 + 2 + (4*sizeof(int)); //Header bytes + size field bytes + data

  //IMPORTANT: Change to serial port that is connected to PC
  Serial.write((uint8_t * )buffer_r, pktSize);
 }

#endif
