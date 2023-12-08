const int BUTTON = 3;
const int LED = 9;
bool isLIGHT = LOW;
bool lastButtonPress = LOW;

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool isButtonPress = digitalRead(BUTTON);
  Serial.print("isButtonPress:");
  Serial.println(isButtonPress);
  if (isButtonPress == HIGH && lastButtonPress==LOW)
  {
    lastButtonPress=HIGH;
    isLIGHT = HIGH;
    delay(1000);
  } else if (isButtonPress == HIGH && lastButtonPress==HIGH)
  {
    lastButtonPress=LOW;
    isLIGHT = LOW;
    delay(1000);
  }  
  digitalWrite(LED,isLIGHT);
}
