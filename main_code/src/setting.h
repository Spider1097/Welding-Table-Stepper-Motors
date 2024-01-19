
#include <Arduino.h>

// main menu
int list_data = 0;
char help;
char choise;
int close_zlozona = 0;
int back_to_mainu = 0;
int change_parameter = 0;
// main menu

// variables to define the movement of the motor
bool close_while_case_1 = 0;
float steps_motor1 = 0;
float set_direction1 = 0;
float set_direction_side1 = 0;
float count1 = 0;
float count2 = 0;
float speed_motor1 = 0;

float steps_motor2 = 0;
float set_direction2 = 0;
float set_direction_side2 = 0;
float speed_motor2 = 0;
// variables to define the movement of the motor

// pins for blutuf
SoftwareSerial BT(A1, A0);
// pins for blutuf

// pins for motor
const int stepPin1 = 6;
const int stepPin2 = 8;
const int dirPin1 = 5;
const int dirPin2 = 7;
#define motorInterfaceType 1
// pins for motor

AccelStepper stepper1 = AccelStepper(motorInterfaceType, stepPin1, dirPin1);
AccelStepper stepper2 = AccelStepper(motorInterfaceType, stepPin2, dirPin2);
