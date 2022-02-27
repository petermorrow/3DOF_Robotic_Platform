// Servo motor control code 
// Operation of savox SA1258TG servo
// PWM signal frequency set manually
// Desired micro seconds specified from calculated Duty cycle


#include <Arduino.h>

String pi_command;

//define servo motor pins
#define servo_1 23
#define servo_2 22
#define servo_3 21
#define servo_4 20

int LED = 13;
int pos = 100;

double min_duty_cycle = 76.8; //Min duty cycle (0 degrees) - calabration for table Max
double max_duty_cycle = 179.2; // Max DC (130 degrees from table max height)

//global servo angles
int servo_angle1 = 100; //default angle - 100 degrees
int servo_angle2 = 100; //default angle - 100 degrees
int servo_angle3 = 100; //default angle - 100 degrees
int servo_angle4 = 100; //default angle - 100 degrees

//string parsing
char messageBuffer[20];
size_t bytesReceived;
bool messageReceived;

void setup() {
  pinMode(servo_1, OUTPUT); //Servo 1 set as output pin
  pinMode(servo_2, OUTPUT);
  pinMode(servo_3, OUTPUT);
  pinMode(servo_4, OUTPUT);

  analogWriteFrequency(servo_1, 333); //set desired operating frequency for savox SA1258TG servo
  // this will set every pin linked to FTM0 timer = 333Hz (Pin: 5, 6, 9, 10, 20, 21, 22, 23)

  //Initialise serial port
  Serial.begin(9600);

  //wait for serial port to connect
  // while(!Serial){
  //   delay(100); //wait for serial port connection
  // }
  
}

void loop() {

  if(Serial.available()){

    
    //parse information from sent string
    bytesReceived = Serial.readBytesUntil('\n', messageBuffer, 20);//read bytes until new line 
    // or until 4 bytes read
    Serial.println("message received =>");
    Serial.println(messageBuffer);

    // parse string - correct parsing
    const char delimiter[] = ",";
    char parsedStrings[4][20]; //4 char strings, each with max 20 chars
    char *token = strtok(messageBuffer, delimiter); //strtok takes in data we want to parse
    // with the delimiter
    // *token - indicates a pointer (point to memory address location)
    // strtok - next time we call - if pass NULL - it will remeber its last location in messageBuffer
    strncpy(parsedStrings[0], token, sizeof(parsedStrings[0]));//store token as its own char array

    // run strtok and strncpy commands for 4 more times - to parse all values
    for(int i = 1; i<4; i++ ){
      token = strtok(NULL, delimiter);//NULL - remebers last location in messageBuffer
      // if token does not = NULL
      strncpy(parsedStrings[i], token, sizeof(parsedStrings[i]));//store token as its own char array
    }

    //print parsed strings
    for(int i =0; i<4; i++){
      Serial.println(parsedStrings[i]);
    }

    //convert stings to int
    Serial.println("Convert to ints");
    servo_angle1 = atoi(parsedStrings[0]); // atoi - convert str to int
    Serial.println(servo_angle1);
    servo_angle2 = atoi(parsedStrings[1]); // atoi - convert str to int
    Serial.println(servo_angle2);
    servo_angle3 = atoi(parsedStrings[2]); // atoi - convert str to int
    Serial.println(servo_angle3);
    servo_angle4 = atoi(parsedStrings[3]); // atoi - convert str to int
    Serial.println(servo_angle4);

  }

  

  
  // map recieved servo angle (0(max)-130(min)) to Duty cycle max an min values
  int duty_cycle_1 = map(servo_angle1, 0, 130, min_duty_cycle, max_duty_cycle);
  int duty_cycle_2 = map(servo_angle2, 0, 130, min_duty_cycle, max_duty_cycle);
  int duty_cycle_3 = map(servo_angle3, 0, 130, min_duty_cycle, max_duty_cycle);
  int duty_cycle_4 = map(servo_angle4, 0, 130, min_duty_cycle, max_duty_cycle);
  analogWrite(servo_1, duty_cycle_1);
  analogWrite(servo_2, duty_cycle_2);
  analogWrite(servo_3, duty_cycle_3);
  analogWrite(servo_4, duty_cycle_4);
  delay(100);
  

}


