#define LED_PIN 2
#define TXD2 17
#define RXD2 16

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  if (Serial2.available()) {

    String cmd = Serial2.readStringUntil('\n');
    cmd.trim();

    if (cmd == "LED_ON") {
      digitalWrite(LED_PIN, HIGH);
    }

    else if (cmd == "LED_OFF") {
      digitalWrite(LED_PIN, LOW);
    }
  }
}