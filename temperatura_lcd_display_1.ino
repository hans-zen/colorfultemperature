#include <Servo.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int a;
int del=3000; // cada cuanto se lee la temperatura
float temperatura;
int B=3975; 
float resistance;

void setup()
{
  Serial.begin(9600); 
  lcd.begin(16, 2);

}

void loop()
{
  a=analogRead(0);
  resistance=(float)(1023-a)*10000/a; 
  temperatura=1/(log(resistance/10000)/B+1/298.15)-273.15;
  lcd.print(temperatura);
  lcd.print(" Grados");
  float calor = 25.00;

  //cambio de color con base en temperatura
  if (temperatura >= calor){
     lcd.setRGB(255,0,0);
    }
  else if(temperatura <= calor){
     lcd.setRGB(0,0,255);
    }
  else{
    lcd.setRGB(0,255,0);
    }  
   //termometro analogo
  delay(del);
  lcd.clear();
}
