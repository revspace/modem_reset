
const int knopje = A2;
const int relais = 9;
const int ledje = A0;

void setup() {
  pinMode(knopje, INPUT_PULLUP);
  pinMode(relais, OUTPUT);
  pinMode(ledje, OUTPUT);
  Serial.begin(115200);
  Serial.println("setup");
}

void loop() {
  if (millis() % 1000 == 0) {
    Serial.println("Ik leef nog!");
    delay(1);
  }
  if (digitalRead(knopje) == LOW) {
    Serial.println("Knopje ingedrukt");
    delay(3000);
    if (digitalRead(knopje) == LOW) {
      Serial.println("Knopje lang genoeg ingedrukt; relais wordt bekrachtigd");
      digitalWrite(relais, HIGH);
      digitalWrite(ledje, HIGH);
      delay(20000);
      digitalWrite(relais, LOW);
      digitalWrite(ledje, LOW);
      Serial.println("Relais vrij");
    }
  }
}
