#include <Wire.h>
#include "DS1307.h"
int ledPin=3;
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
  int heure=clock.hour;
  int minute=clock.minute;
  int seconde=clock.second;
  int mois=clock.month;
  int jour=clock.dayOfMonth;

  
    clock.getTime();
    Serial.print(heure, DEC);
    Serial.print(":");
    Serial.print(minute, DEC);
    Serial.print(":");
    Serial.print(seconde, DEC);
    Serial.print("  ");
    Serial.print(mois, DEC);
    Serial.print("/");
    Serial.print(jour, DEC);
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


{
if ((heure>=00)and(heure<6))
  digitalWrite(ledPin, LOW);
else
  digitalWrite(ledPin, HIGH);
}

{
if ( (mois>=5)and(mois<9) ){
  if ((heure>=2)and(heure<6)){
    digitalWrite(ledPin, LOW);
  }
  else{
    digitalWrite(ledPin, HIGH);
  }
}
else
  digitalWrite(ledPin, HIGH);}
}
