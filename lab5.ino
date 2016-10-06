/*  Aaron Ayrault, Jason Do, Margaret Baxter, Landon Prewitt 
 *  Lab 5: LIDAR/ultrasonic sensor 
 *  Sources: www.HowToMechatronics.com
 */
 
#include <Servo.h>.

//pin locations
const int outputPin = 10;
const int ultrasound = 11;

//variable declarations
long duration;
int distance;
Servo myServo;

void setup() {
  //setting input and output pins
  pinMode(outputPin, OUTPUT);
  pinMode(ultrasound, INPUT);
 
  //initialize program and servo
  Serial.begin(9600);
  myServo.attach(12);
}

void loop() {
  //loop to print out distance while moving in the initial direction
  for(int i = 15; i <= 165; ++i){  
    myServo.write(i);
    delay(30);
    distance = getDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  //loop to print out distance while moving the other direction
  for(int i = 165; i > 15; --i){  
    myServo.write(i);
    delay(30);
    distance = getDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

//get distance to scanned object (if in range)
int getDistance(){ 
  digitalWrite(outputPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  duration = pulseIn(ultrasound, HIGH);
  distance= duration*0.034/2;
  return distance;
}
