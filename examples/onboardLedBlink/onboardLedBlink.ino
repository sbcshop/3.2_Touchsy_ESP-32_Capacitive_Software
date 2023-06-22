const byte LED = 3; // onboard LED connected at GPIO0 

void setup(void) {
  pinMode(LED, OUTPUT); // Set PIN as OUTPUT
}

void loop() {
  digitalWrite(LED, HIGH); // Turn ON
  delay(1000);
  digitalWrite(LED, LOW); // Turn OFF
  delay(1000);
}
