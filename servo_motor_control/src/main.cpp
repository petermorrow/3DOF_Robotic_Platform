// Initial test of servo motor control code 
// Test operation of savox SA1258TG servo
// PWM signal frequency set manually
// Desired micro seconds specified from calculated Duty cycle
// test change code

#include <Arduino.h>

int servo_1 = 23;
int servo_2 = 22;
int servo_3 = 21;
int servo_4 = 20;
int LED = 13;
int pos = 100;

double test_angle = 127.872;

double test_angle_2 = 120;

double test_angle_3 = 60;
double test_angle_4 = 120;

void setup() {
  pinMode(servo_1, OUTPUT); //PWM set as output pin
  analogWriteFrequency(servo_1, 333); //set desired operating frequency for savox SA1258TG servo
  // this will set every pin linked to FTM0 timer = 333Hz (Pin: 5, 6, 9, 10, 20, 21, 22, 23)
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(servo_1, test_angle_2); // Nutral position - 1500 micro seconds
  analogWrite(servo_2, test_angle_2); // Nutral position - 1500 micro seconds
  analogWrite(servo_3, test_angle_2); // Nutral position - 1500 micro seconds
  analogWrite(servo_4, test_angle_2); // Nutral position - 1500 micro seconds
  delay(100);

  analogWrite(servo_1, test_angle_3); // Nutral position - 1500 micro seconds
  analogWrite(servo_2, test_angle_3); // Nutral position - 1500 micro seconds
  analogWrite(servo_3, test_angle_3); // Nutral position - 1500 micro seconds
  analogWrite(servo_4, test_angle_3); // Nutral position - 1500 micro seconds
  delay(250);

}



