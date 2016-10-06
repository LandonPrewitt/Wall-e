/*  Aaron Ayrault, Jason Do, Margaret Baxter, Landon Prewitt 
 *  Lab 5: LIDAR/ultrasonic sensor 
 *  Sources: www.HowToMechatronics.com
 */
 
#include <Servo.h>.

//pin locations
const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(12);
}

void loop() {
  //loop to print out distance while mofing in the inital direction
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
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance;
}
