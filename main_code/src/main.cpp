#include <Arduino.h>
#include <AccelStepper.h>
#include <SoftwareSerial.h>
#include <setting.h>
#include <function.h>

void setup()
{
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
}

void loop()
{

  if (list_data == 0)
  {
    BT.println("-----------------");
    BT.println("choose option:");
    delay(600);
    BT.println("0 => help");
    delay(600);
    BT.println("1 => motor 1");
    delay(600);
    BT.println("2 => motor 2");
    delay(600);
    BT.println("3 => motor1 & motor2");
    delay(600);
    list_data++;
  }

  if (BT.available() > 0)
  {

    choise = BT.parseInt();
    switch (choise)
    {
    case 0:
      BT.println("The speed of motor1 must be less than the speed of motor2 by a factor of 2 (linear motion)");
      delay(800);

      list_data = 0;

      break;
    case 1:
      motor1();
      break;
    case 2:
      silnik2();
      break;
    case 3:
      ruch_zlozony();
      break;
    }
  }
}
