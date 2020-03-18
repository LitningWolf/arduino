#include "RTClib.h"
#include <Adafruit_MCP23017.h>
#define NUM_ONES_LEDS 4

RTC_DS3231 rtc;
Adafruit_MCP23017 mcp1;
Adafruit_MCP23017 mcp2;


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

mcp2.begin(001);
mcp2.pinMode(0, OUTPUT);//1
mcp2.pinMode(1, OUTPUT);//2
mcp2.pinMode(2, OUTPUT);//3
mcp2.pinMode(3, OUTPUT);//4
mcp2.pinMode(4, OUTPUT);//5
mcp2.pinMode(5, OUTPUT);//6
mcp2.pinMode(6, OUTPUT);//7
mcp2.pinMode(7, OUTPUT);//8
mcp2.pinMode(8, OUTPUT);//9
mcp2.pinMode(9, OUTPUT);//10
mcp2.pinMode(10, OUTPUT);//11
mcp2.pinMode(11, OUTPUT);//12

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
// leds 1-4
if (now.minute() % 5 == 1)
  mcp1.digitalWrite(0, HIGH);
if (now.minute() % 5 == 2){
  mcp1.digitalWrite(0, HIGH);
  mcp1.digitalWrite(1, HIGH);}
if (now.minute() % 5 == 3){
  mcp1.digitalWrite(0, HIGH);
  mcp1.digitalWrite(1, HIGH);
  mcp1.digitalWrite(2, HIGH);}
if (now.minute() % 5 == 4){
  mcp1.digitalWrite(0, HIGH);
  mcp1.digitalWrite(1, HIGH);
  mcp1.digitalWrite(2, HIGH);
  mcp1.digitalWrite(3, HIGH);}
  
//leds 5-55
if (now.minute() == 5)
  mcp1.digitalWrite(4, HIGH);
if (now.minute() == 10){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);}
if (now.minute() == 15){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);}
if (now.minute() == 20){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);
  mcp1.digitalWrite(7, HIGH);}
if (now.minute() == 25){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);
  mcp1.digitalWrite(7, HIGH);
  mcp1.digitalWrite(8, HIGH);}
if (now.minute() == 30){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);
  mcp1.digitalWrite(7, HIGH);
  mcp1.digitalWrite(8, HIGH);
  mcp1.digitalWrite(9, HIGH);}
if (now.minute() == 35){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);
  mcp1.digitalWrite(7, HIGH);
  mcp1.digitalWrite(8, HIGH);
  mcp1.digitalWrite(9, HIGH);
  mcp1.digitalWrite(10, HIGH);}
if (now.minute() == 40){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);
  mcp1.digitalWrite(7, HIGH);
  mcp1.digitalWrite(8, HIGH);
  mcp1.digitalWrite(9, HIGH);
  mcp1.digitalWrite(10, HIGH);
  mcp1.digitalWrite(11, HIGH);}
if (now.minute() == 45){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);
  mcp1.digitalWrite(7, HIGH);
  mcp1.digitalWrite(8, HIGH);
  mcp1.digitalWrite(9, HIGH);
  mcp1.digitalWrite(10, HIGH);
  mcp1.digitalWrite(11, HIGH);
  mcp1.digitalWrite(12, HIGH);}
if (now.minute() == 50){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);
  mcp1.digitalWrite(7, HIGH);
  mcp1.digitalWrite(8, HIGH);
  mcp1.digitalWrite(9, HIGH);
  mcp1.digitalWrite(10, HIGH);
  mcp1.digitalWrite(11, HIGH);
  mcp1.digitalWrite(12, HIGH);
  mcp1.digitalWrite(13, HIGH);}
if (now.minute() == 55){
  mcp1.digitalWrite(4, HIGH);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);
  mcp1.digitalWrite(7, HIGH);
  mcp1.digitalWrite(8, HIGH);
  mcp1.digitalWrite(9, HIGH);
  mcp1.digitalWrite(10, HIGH);
  mcp1.digitalWrite(11, HIGH);
  mcp1.digitalWrite(12, HIGH);
  mcp1.digitalWrite(13, HIGH);
  mcp1.digitalWrite(14, HIGH);}
  
// leds 1-12 hours
if (now.hour() == 1)
  mcp2.digitalWrite(0, HIGH);
if (now.hour() == 2){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);}
if (now.hour() == 3){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);}
if (now.hour() == 4){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);}
if (now.hour() == 5){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);}
if (now.hour() == 6){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);}
if (now.hour() == 7){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);}
if (now.hour() == 8){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);}
if (now.hour() == 9){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);
  mcp2.digitalWrite(8, HIGH);}
if (now.hour() == 10){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);
  mcp2.digitalWrite(8, HIGH);
  mcp2.digitalWrite(9, HIGH);}
if (now.hour() == 11){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);
  mcp2.digitalWrite(8, HIGH);
  mcp2.digitalWrite(9, HIGH);
  mcp2.digitalWrite(10, HIGH);}
if (now.hour() == 12){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);
  mcp2.digitalWrite(8, HIGH);
  mcp2.digitalWrite(9, HIGH);
  mcp2.digitalWrite(10, HIGH);
  mcp2.digitalWrite(11, HIGH);}
if (now.hour() == 13)
  mcp2.digitalWrite(0, HIGH);
if (now.hour() == 14){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);}
if (now.hour() == 15){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);}
if (now.hour() == 16){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);}
if (now.hour() == 17){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);}
if (now.hour() == 18){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);}
if (now.hour() == 19){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);}
if (now.hour() == 20){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);}
if (now.hour() == 21){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);
  mcp2.digitalWrite(8, HIGH);}
if (now.hour() == 22){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);
  mcp2.digitalWrite(8, HIGH);
  mcp2.digitalWrite(9, HIGH);}
if (now.hour() == 23){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);
  mcp2.digitalWrite(8, HIGH);
  mcp2.digitalWrite(9, HIGH);
  mcp2.digitalWrite(10, HIGH);}
if (now.hour() == 0){
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, HIGH);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, HIGH);
  mcp2.digitalWrite(4, HIGH);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, HIGH);
  mcp2.digitalWrite(8, HIGH);
  mcp2.digitalWrite(9, HIGH);
  mcp2.digitalWrite(10, HIGH);
  mcp2.digitalWrite(11, HIGH);}


//off
// leds 1-4
if (now.minute() % 5 == 0){
  mcp1.digitalWrite(0, LOW);
  mcp1.digitalWrite(1, LOW);
  mcp1.digitalWrite(2, LOW);
  mcp1.digitalWrite(3, LOW);
}
// leds 5-55
if (now.minute() / 5 == 0){
  mcp1.digitalWrite(4, LOW);
  mcp1.digitalWrite(5, LOW);
  mcp1.digitalWrite(6, LOW);
  mcp1.digitalWrite(7, LOW);
  mcp1.digitalWrite(8, LOW);
  mcp1.digitalWrite(9, LOW);
  mcp1.digitalWrite(10, LOW);
  mcp1.digitalWrite(11, LOW);
  mcp1.digitalWrite(12, LOW);
  mcp1.digitalWrite(13, LOW);
  mcp1.digitalWrite(14, LOW);
}
// leds 1-12
if (now.hour() == 1){
  mcp2.digitalWrite(1, LOW);
  mcp2.digitalWrite(2, LOW);
  mcp2.digitalWrite(3, LOW);
  mcp2.digitalWrite(4, LOW);
  mcp2.digitalWrite(5, LOW);
  mcp2.digitalWrite(6, LOW);
  mcp2.digitalWrite(7, LOW);
  mcp2.digitalWrite(8, LOW);
  mcp2.digitalWrite(9, LOW);
  mcp2.digitalWrite(10, LOW);
  mcp2.digitalWrite(11, LOW);
}
if (now.hour() == 13){
  mcp2.digitalWrite(1, LOW);
  mcp2.digitalWrite(2, LOW);
  mcp2.digitalWrite(3, LOW);
  mcp2.digitalWrite(4, LOW);
  mcp2.digitalWrite(5, LOW);
  mcp2.digitalWrite(6, LOW);
  mcp2.digitalWrite(7, LOW);
  mcp2.digitalWrite(8, LOW);
  mcp2.digitalWrite(9, LOW);
  mcp2.digitalWrite(10, LOW);
  mcp2.digitalWrite(11, LOW);
}
}
