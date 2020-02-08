#include "RTClib.h"
#include <Adafruit_MCP23017.h>
#define NUM_ONES_LEDS 4

RTC_DS3231 rtc;
Adafruit_MCP23017 mcp1;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
//mcp 
mcp1.begin();
mcp1.pinMode(0, OUTPUT);//1
mcp1.pinMode(1, OUTPUT);//2
mcp1.pinMode(2, OUTPUT);//3
mcp1.pinMode(3, OUTPUT);//4
mcp1.pinMode(4, OUTPUT);//5
mcp1.pinMode(5, OUTPUT);//10
mcp1.pinMode(6, OUTPUT);//15
mcp1.pinMode(7, OUTPUT);//20
mcp1.pinMode(8, OUTPUT);//25
mcp1.pinMode(9, OUTPUT);//30
mcp1.pinMode(10, OUTPUT);//35
mcp1.pinMode(11, OUTPUT);//40
mcp1.pinMode(12, OUTPUT);//45
mcp1.pinMode(13, OUTPUT);//50
mcp1.pinMode(14, OUTPUT);//55


//light

//rtc
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif

  Serial.begin(9600);

  delay(500); // wait for console opening
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
  //rtc
    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");

    Serial.println();
    delay(1000);

    //lights
//on

if (now.minute() % 5 == 1)
  mcp1.digitalWrite(0, HIGH);
if (now.minute() % 5 == 2)
  mcp1.digitalWrite(1, HIGH);
if (now.minute() % 5 == 3)
  mcp1.digitalWrite(2, HIGH);
if (now.minute() % 5 == 4)
  mcp1.digitalWrite(3, HIGH);
//off
if (now.minute() % 10 == 0)
  mcp1.digitalWrite(0, LOW);
if (now.minute() % 10 == 0)
  mcp1.digitalWrite(1, LOW);
if (now.minute() % 10 == 0)
  mcp1.digitalWrite(2, LOW);
if (now.minute() % 10 == 0)
  mcp1.digitalWrite(3, LOW);
if (now.minute() % 10 == 5)
  mcp1.digitalWrite(0, LOW);
if (now.minute() % 10 == 5)
  mcp1.digitalWrite(1, LOW);
if (now.minute() % 10 == 5)
  mcp1.digitalWrite(2, LOW);
if (now.minute() % 10 == 5)
  mcp1.digitalWrite(3, LOW);
}
