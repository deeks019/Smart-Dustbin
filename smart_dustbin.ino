#include <Servo.h>

Servo servo;
int trigPin = 9;
int echoPin = 10;
long duration;
int distance;

void setup() {
  servo.attach(5);       
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.write(0);          
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);   
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance < 10) {  
    servo.write(0);    
    delay(2000);       
    servo.write(90);       }
}
