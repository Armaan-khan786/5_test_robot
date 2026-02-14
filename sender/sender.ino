#define TXD2 17
#define RXD2 16
#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);   // Start with LED OFF

  delay(2000);
  Serial.println("SENDER_READY");
}

void loop() {

  if (Serial.available()) {

    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "SYNC_ON") {
      Serial2.println("LED_ON");
      digitalWrite(LED_PIN, HIGH);   // 👈 Turn sender LED ON
      Serial.println("ACK_ON");
    }

    else if (cmd == "SYNC_OFF") {
      Serial2.println("LED_OFF");
      digitalWrite(LED_PIN, LOW);    // 👈 Turn sender LED OFF
      Serial.println("ACK_OFF");
    }

    else if (cmd == "PING") {
      Serial.println("PONG");
    }

    else if (cmd == ".pi") {
      Serial.println("PI=3.14159");
    }

    else if (cmd == ".reboot") {
      Serial.println("REBOOTING...");
      delay(1000);
      ESP.restart();
    }

    else {
      Serial.println("INVALID_CMD");
    }
  }
}