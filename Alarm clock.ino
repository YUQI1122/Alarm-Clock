#include <Wire.h>
#include <RTClib.h>
int toneVal;
float sinVal;

RTC_DS1307 RTC;

void setup () {
    Serial.begin(9600);
    pinMode(12,OUTPUT);
    Wire.begin();
    RTC.begin();
    RTC.adjust(DateTime(__DATE__, __TIME__));
}

void loop () {
    DateTime now = RTC.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    delay(500);
     if(now.hour()==12&&now.minute()==4&&now.second()>0){
        tone(12,131);
        delay(1000);        
        tone(12,532);
        delay(1000);        
        tone(12,784);
        delay(1000);
        noTone(12);
    }else{
      noTone(12);
    }

}
