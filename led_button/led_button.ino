const int BUTTON = 3;
const int LED = 9;
bool isLIGHT = LOW;
bool currentStateButton = LOW;
bool lastStateButton = LOW;
bool current = LOW;

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

bool debounceButton (bool last) {
  bool current = digitalRead(BUTTON);
  if (current != last) {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}

void loop() {
  currentStateButton = debounceButton(lastStateButton);
  if (lastStateButton==LOW && currentStateButton==HIGH){
    isLIGHT=!isLIGHT;
    Serial.print("isLIGHT: ");
    Serial.println(isLIGHT);
  }    
  digitalWrite(LED,isLIGHT);
  lastStateButton = currentStateButton;
}
