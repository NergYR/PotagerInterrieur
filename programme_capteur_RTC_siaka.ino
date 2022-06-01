#include <Wire.h>
#include "DS1307.h"
 
DS1307 clock;//define a object of DS1307 class
void setup()
{
    Serial.begin(9600);
    clock.begin();
    clock.fillByYMD(2022,5,18);//Jan 19,2013
    clock.fillByHMS(14,30,30);//15:28 30"
    clock.fillDayOfWeek(WED);//Saturday
    clock.setTime();//write time to the RTC chip
}
void loop()
{
    printTime();
}
    /*Function: Display time on the serial monitor*/
void printTime()
{
    clock.getTime();
    Serial.print(clock.hour, DEC);
    Serial.print(":");
    Serial.print(clock.minute, DEC);
    Serial.print(":");
    Serial.print(clock.second, DEC);
    Serial.print("  ");
    Serial.print(clock.month, DEC);
    Serial.print("/");
    Serial.print(clock.dayOfMonth, DEC);
    Serial.print("/");
    Serial.print(clock.year+2000, DEC);
    Serial.print(" ");
    Serial.print(clock.dayOfMonth);
    Serial.print("*");
    switch (clock.dayOfWeek)// Friendly printout the weekday
    {
        case MON:
        Serial.print("LUN");
        break;
        case TUE:
        Serial.print("MAR");
        break;
        case WED:
        Serial.print("WED");
        break;
        case THU:
        Serial.print("JEU");
        break;
        case FRI:
        Serial.print("VEN");
        break;
        case SAT:
        Serial.print("SAN");
        break;
        case SUN:
        Serial.print("DIM");
        break;
    }
    Serial.println(" ");

if ((heure>=00)and(heure<6))
  digitalWrite(ledPin, LOW)

else
  digitalWrite(ledPin, HIGH)

}
