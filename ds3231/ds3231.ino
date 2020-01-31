#include "RTClib.h"
#include <Adafruit_MCP23017.h>
#define NUM_ONES_LEDS 4

RTC_DS3231 rtc;
Adafruit_MCP23017 mcp;

    DateTime now = rtc.now();
int onesledpins[4] = {2, 3, 4, 5}; // LED pin numbers
int ones = (now.minute() % 5);
int led;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
//mcp 
mcp.begin();
//rtc
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif

  Serial.begin(9600);

  delay(500); // wait for console opening
Serial.println("start");
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
Serial.println("rtc pass");
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
  //rtc
  Serial.println("time");
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
Serial.println("time pass");
    //lights
    for (led = 0; led < NUM_ONES_LEDS; ++led) {
    pinMode(onesledpins[led], OUTPUT);
Serial.println("led pass");
   }
}
