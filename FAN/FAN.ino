#include <LiquidCrystal.h>

  LiquidCrystal lcd(10,9,5,4,3,2);

const int trigPin = 8;
const int echoPin = 7;
byte fan = 6;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
    analogWrite(6,100);
    lcd.begin(16,2);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(fan,OUTPUT);

    
}

void loop() {
long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance > 30){
digitalWrite(fan, LOW);
}else if(distance < 5){
digitalWrite(fan, LOW);
}else{
digitalWrite(fan, HIGH);
}
    
    delay(200);
    
}
