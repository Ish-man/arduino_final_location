#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;// Here we make pin 4 as RX of arduino & pin 3 as TX of arduino 
static const uint32_t GPSBaud = 9600;


TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(9600);
  ss.begin(GPSBaud);

 
}

void loop()
{
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();
//      delay(4000);  

//  if (millis() > 5000 && gps.charsProcessed() < 10)
//  {
////    Serial.println(F("0+0 "));
//    while(true);
//  }
}

void displayInfo()
{ 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 7);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 7);
    delay(1000);
//    Serial.print(F(" "));

  }
  else
  {
//    Serial.print(F("0+0 "));
  }

  if (gps.time.isValid())
  {
    // Convert UTC time to IST
    int hourIST = (gps.time.hour() + 5 ) % 24; // Add 5 hours
    int minuteIST = (gps.time.minute() + 30) % 60; // Add 30 minutes

//    if (hourIST < 10) Serial.print("0");
//    Serial.print(hourIST);
////    Serial.print(F("/"));
//    if (minuteIST < 10) Serial.print("0");
//    Serial.print(minuteIST);
////    Serial.print(F("/"));
//    if (gps.time.second() < 10) Serial.print("0");
//    Serial.print(gps.time.second());
  }
  else
  {
//    Serial.print(F("0+0 "));
  }

  Serial.println();
}
