# if (EXECUTE==1)
#include "Arduino.h"
//The setup function is called once at startup of the sketch
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

/*prototypes */
void plot1(int data1, int data2, int data3, int data4);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  //Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
}
int buffer_r[20];

void loop(void)
{
  int data2;
  int data3;
  int data4;
  //int temperature0;
  float temperature0;
  int factor = 100;
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");

  //Serial.print("Temperature for Device 1 is: ");
  temperature0 = sensors.getTempCByIndex(0); // Why "byIndex"?
  //printf("temp:%f",temperature0);
  //Serial.print("Temperature for Device 2 is: ");
  //temperature = sensors.getTempCByIndex(1);
  Serial.println(temperature0);
  //Serial.print("END");
  //Serial.println(temperature);
    // You can have more than one IC on the same bus.
    // 0 refers to the first IC on the wire
   data2 = 36;
   data3 = 37;
   data4 = 38;

  //plot1(temperature0*factor,data2*factor,data3*factor,data4*factor);
  delay(10);
}

void plot1(int data1, int data2, int data3, int data4)
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
