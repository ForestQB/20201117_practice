void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  int PIR = digitalRead(4);
  if (PIR == 1)
  {
    Serial.println("有人");
    digitalWrite(3, HIGH);
  }
  else
  {
    Serial.println("沒人");
    digitalWrite(3, LOW);
  }
  Serial.println(PIR);
  delay(500);

}
