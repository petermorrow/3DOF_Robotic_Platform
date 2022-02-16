// Servo motor control code 
// Operation of savox SA1258TG servo
// PWM signal frequency set manually
// Desired micro seconds specified from calculated Duty cycle


#include <Arduino.h>

int servo_1 = 23;
int servo_2 = 22;
int servo_3 = 21;
int servo_4 = 20;
int LED = 13;
int pos = 100;


double min_duty_cycle = 76.8; //Min duty cycle (0 degrees) - calabration for table Max
double max_duty_cycle = 179.2; // Max DC (130 degrees from table max height)

int servo_angle = 10;

void setup() {
  pinMode(servo_1, OUTPUT); //Servo 1 set as output pin
  pinMode(servo_2, OUTPUT);
  pinMode(servo_3, OUTPUT);
  pinMode(servo_4, OUTPUT);

  analogWriteFrequency(servo_1, 333); //set desired operating frequency for savox SA1258TG servo
  // this will set every pin linked to FTM0 timer = 333Hz (Pin: 5, 6, 9, 10, 20, 21, 22, 23)

  
  
}

void loop() {
  //put your main code here, to run repeatedly:

  // map recieved servo angle (0(max)-130(min)) to Duty cycle max an min values

  servo_angle = 100;
  int angle = map(servo_angle, 0, 130, min_duty_cycle, 179.2);
  analogWrite(servo_1, angle); // Nutral position - 1500 micro seconds
  analogWrite(servo_2, angle); // Nutral position - 1500 micro seconds
  analogWrite(servo_3, angle); // Nutral position - 1500 micro seconds
  analogWrite(servo_4, angle); // Nutral position - 1500 micro seconds
  delay(300);
  

}



// step between Max and min values

// for(servo_angle = 0; servo_angle<=130; servo_angle++){
//     int angle = map(servo_angle, 0, 130, 76.8, 179.2);
//     analogWrite(servo_1, angle); // Nutral position - 1500 micro seconds
//     analogWrite(servo_2, angle); // Nutral position - 1500 micro seconds
//     analogWrite(servo_3, angle); // Nutral position - 1500 micro seconds
//     analogWrite(servo_4, angle); // Nutral position - 1500 micro seconds
//     delay(10);

//   }

