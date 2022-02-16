// Initial test of servo motor control code 
// Test operation of savox SA1258TG servo
// PWM signal frequency set manually
// Desired micro seconds specified from calculated Duty cycle

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

  // analogWrite(servo_1, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_2, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_3, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_4, 100); // Nutral position - 1500 micro seconds
  // delay(1000);

  // for(int i =0; i<=20; i++){
  //   analogWrite(servo_1, pos); // Nutral position - 1500 micro seconds
  //   analogWrite(servo_2, pos+i); // Nutral position - 1500 micro seconds
  //   analogWrite(servo_3, pos); // Nutral position - 1500 micro seconds
  //   analogWrite(servo_4, pos-i); // Nutral position - 1500 micro seconds
  //   delay(100);
  // }

  // analogWrite(servo_1, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_2, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_3, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_4, 100); // Nutral position - 1500 micro seconds
  // delay(1000);

  // for(int i =0; i<=20; i++){
  //   analogWrite(servo_1, pos); // Nutral position - 1500 micro seconds
  //   analogWrite(servo_2, pos-i); // Nutral position - 1500 micro seconds
  //   analogWrite(servo_3, pos); // Nutral position - 1500 micro seconds
  //   analogWrite(servo_4, pos+i); // Nutral position - 1500 micro seconds
  //   delay(100);
  // }

  // analogWrite(servo_1, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_2, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_3, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_4, 100); // Nutral position - 1500 micro seconds
  // delay(1000);

  // analogWrite(servo_1, 120); // Nutral position - 1500 micro seconds
  // analogWrite(servo_2, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_3, 80); // Nutral position - 1500 micro seconds
  // analogWrite(servo_4, 100); // Nutral position - 1500 micro seconds
  // delay(1000);

  // analogWrite(servo_1, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_2, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_3, 100); // Nutral position - 1500 micro seconds
  // analogWrite(servo_4, 100); // Nutral position - 1500 micro seconds
  // delay(1000);

  // analogWrite(servo_1, test_angle_4); // Nutral position - 1500 micro seconds
  // analogWrite(servo_2, test_angle_4); // Nutral position - 1500 micro seconds
  // analogWrite(servo_3, test_angle_4); // Nutral position - 1500 micro seconds
  // analogWrite(servo_4, test_angle_4); // Nutral position - 1500 micro seconds
  // delay(2000);


  // delay(5000);

  // analogWrite(servo_1, 187.5456); // Max position - 2200 micro seconds
  // delay(1000);
  // analogWrite(servo_1, 68.1984); // Min position - 800 micro seconds
  // delay(1000);
 
}



// analogWrite(servo_1, 85.248); //  1000 micro seconds
// delay(500);
// analogWrite(servo_1, 161.9712); //  1900 micro seconds
// delay(500);
// analogWrite(servo_1, 170.496); //  2000 micro seconds
// delay(500);


// #include <Servo.h>
// Servo servo1;
// int servoPin = 23;
// int pos = 1000;

// void setup(){
//   servo1.attach(servoPin);
// }

// void loop(){

//   //servo1.writeMicroseconds(pos);
//   servo1.writeMicroseconds(pos);
//   for(pos =1000; pos<=2000; pos=pos+100){
//     servo1.writeMicroseconds(pos);
//     delay(100);
//   }
//   for(pos =2000; pos>=1000; pos=pos-100){
//     servo1.writeMicroseconds(pos);
//     delay(100);
//   }
// }

