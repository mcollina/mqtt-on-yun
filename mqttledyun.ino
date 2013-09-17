
#include <Bridge.h>
#include <Process.h>
#include <Serial.h>

int ledPin = 13;

Process subscribe;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  Bridge.begin();
  digitalWrite(ledPin, LOW);
  
  delay(1000);
  
  digitalWrite(ledPin, HIGH);
  
  Serial.begin(9600);
  
  
  digitalWrite(ledPin, LOW);
  
  delay(1000);
  
  digitalWrite(ledPin, HIGH);
  
  
  // put your setup code here, to run once:
  
  Serial.print("Welcome to MQTT led!");
  Serial.flush();
  
  subscribe.runShellCommandAsynchronously("/root/subard.py");
  Serial.print("mqtt connected");
  Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(subscribe.available() < 0) {
    return;
  }
  
  char incomingByte = subscribe.read();
  Serial.print(incomingByte);
  Serial.flush();
  
  if (incomingByte == 'H') {
    digitalWrite(ledPin, HIGH);
  }
  
  if (incomingByte == 'L') {
    digitalWrite(ledPin, LOW);
  }
}
