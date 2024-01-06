#define motorPin 9 
#define ledPin 10
#define potPin A0 

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
    int potValue = analogRead(potPin);
    int motorValue = map(potValue,0,1023,0,255);
    int ledValue = motorValue;
    Serial.print("motorValue:");
    Serial.println(motorValue);
    analogWrite(motorPin,motorValue);
    analogWrite(ledPin,ledValue);
    delay(100);
}
