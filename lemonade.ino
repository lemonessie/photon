int waterPin = D6;
int mixPin = D7;

void setup() {
  pinMode(waterPin, OUTPUT);
  pinMode(mixPin, OUTPUT);

  Spark.function("waterMe", waterMe);
  Spark.function("mixMe", mixMe);

  Serial.begin(9600);
}

void loop() {
  /*mixMe("1000");
  waterMe("2000");*/
}
int togglePin(int pin, long duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
}
int waterMe(String command) {
  int duration = command.toInt();
  Serial.print("Water for ");
  Serial.print(duration);
  Serial.print(" ms\n");
  togglePin(waterPin, duration);
  return 0;
}

int mixMe(String command) {
  int duration = command.toInt();
  Serial.print("Concentrate for ");
  Serial.print(duration);
  Serial.print(" ms\n");
  togglePin(mixPin, duration);
  return 0;
}
