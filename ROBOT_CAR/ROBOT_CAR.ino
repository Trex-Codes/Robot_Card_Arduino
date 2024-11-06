char t;

void setup() {
  pinMode(13, OUTPUT); // Left motors forward
  pinMode(12, OUTPUT); // Left motors reverse
  pinMode(11, OUTPUT); // Right motors forward
  pinMode(10, OUTPUT); // Right motors reverse
  pinMode(9, OUTPUT);  // LED
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'F') { // Move forward (all motors rotate in forward direction)
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
  }
  else if (t == 'G') { // Move reverse (all motors rotate in reverse direction)
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
  }
  else if (t == 'R') { // Turn right (right side motors rotate in forward direction)
    digitalWrite(11, HIGH);
  }
  else if (t == 'L') { // Turn left (left side motors rotate in forward direction)
    digitalWrite(13, HIGH);
  }
  else if (t == 'W') { // Turn LED on
    digitalWrite(9, HIGH);
  }
  else if (t == 'w') { // Turn LED off
    digitalWrite(9, LOW);
  }
  else if (t == 'S') { // STOP (all motors stop)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  delay(100);
}