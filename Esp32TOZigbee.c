#include <SoftwareSerial.h>
const int trigPin = 23;
const int echoPin = 22;

void setup() {
  Serial.begin(115200);
  zigbeeSerial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance_cm;
  
  // Clear the trigger pin before measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse from the echo pin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance_cm = duration * 0.034 / 2;
  zigbeeSerial.write(distance_cm);
  // Print the measured distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  
  // Add a delay between measurements
  delay(1000);
}
