#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);


unsigned int pos0 = 200; // ancho de pulso en cuentas para pocicion 0°ish
unsigned int pos180 = 500; // ancho de pulso en cuentas para la pocicion 180°ish
//flags for min angle
bool flagMin_1 = true, flagMin_2 = true, flagMin_3 = true, flagMin_4 = true;
//flags for max angle
bool flagMax_1 = false, flagMax_2 = false, flagMax_3 = false, flagMax_4 = false;
//variables for the millis clock
unsigned int reloj_1, reloj_2, reloj_3, reloj_4;
int duty_1 = pos0, duty_2 = pos0, duty_3 = pos0, duty_4 = pos0;
//this changes the speed of the motors
int limite_1 = 10;
int limite_2 = 20;
int limite_3 = 30;
int limite_4 = 40;

void setup() {
  servos.begin();
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
}


void loop() {
  //-------------------------------------------------------------------------------------------------------------------------------------------------------
  //motores del 1 al 4
  //-------------------------------------------------------------------------------------------------------------------------------------------------------
  if (millis() - reloj_1 > limite_1)
  {
    if (duty_1 <= 200)
    {
      flagMin_1 = true;
      flagMax_1 = false;
    }
    if (flagMin_1 == true)
    {
      duty_1 = duty_1 + 1;
    }
    if (duty_1 >= 250)
    {
      flagMax_1 = true;
      flagMin_1 = false;
    }
    if (flagMax_1 == true)
    {
      duty_1 = duty_1 - 1;
    }
    servos.setPWM(1, 0, duty_1);
    servos.setPWM(2, 0, duty_1);
    servos.setPWM(3, 0, duty_1);
    servos.setPWM(4, 0, duty_1);
    reloj_1 = millis();
  }
  //-------------------------------------------------------------------------------------------------------------------------------------------------------
  //motores del 5 al 9
  //-------------------------------------------------------------------------------------------------------------------------------------------------------
  if (millis() - reloj_2 > limite_2)
  {
    if (duty_2 <= 250)
    {
      flagMin_2 = true;
      flagMax_2 = false;
    }
    if (flagMin_2 == true)
    {
      duty_2 = duty_2 + 1;
    }
    if (duty_2 >= 300)
    {
      flagMax_2 = true;
      flagMin_2 = false;
    }
    if (flagMax_2 == true)
    {
      duty_2 = duty_2 - 1;
    }
    servos.setPWM(5, 0, duty_2);
    servos.setPWM(6, 0, duty_2);
    servos.setPWM(7, 0, duty_2);
    servos.setPWM(8, 0, duty_2);
    reloj_2 = millis();
  }
  //-------------------------------------------------------------------------------------------------------------------------------------------------------
  //motores del 9 al 12
  //-------------------------------------------------------------------------------------------------------------------------------------------------------
  if (millis() - reloj_3 > limite_3)
  {
    if (duty_3 <= 300)
    {
      flagMin_3 = true;
      flagMax_3 = false;
    }
    if (flagMin_3 == true)
    {
      duty_3 = duty_3 + 1;
    }
    if (duty_3 >= 350)
    {
      flagMax_3 = true;
      flagMin_3 = false;
    }
    if (flagMax_3 == true)
    {
      duty_3 = duty_3 - 1;
    }
    servos.setPWM(9, 0, duty_3);
    servos.setPWM(10, 0, duty_3);
    servos.setPWM(11, 0, duty_3);
    servos.setPWM(12, 0, duty_3);
    reloj_3 = millis();
  }
  //-------------------------------------------------------------------------------------------------------------------------------------------------------
  //motores del 13 al 16
  //-------------------------------------------------------------------------------------------------------------------------------------------------------
  if (millis() - reloj_4 > limite_4)
  {
    if (duty_4 <= 350)
    {
      flagMin_4 = true;
      flagMax_4 = false;
    }
    if (flagMin_4 == true)
    {
      duty_4 = duty_4 + 1;
    }
    if (duty_4 >= 400)
    {
      flagMax_4 = true;
      flagMin_4 = false;
    }
    if (flagMax_4 == true)
    {
      duty_4 = duty_4 - 1;
    }
    servos.setPWM(13, 0, duty_4);
    servos.setPWM(14, 0, duty_4);
    servos.setPWM(15, 0, duty_4);
    servos.setPWM(16, 0, duty_4);
    reloj_4 = millis();
  }
}
