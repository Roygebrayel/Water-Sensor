const int analogInPin = A0;
int sensorValue = 0;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int buzzer = 5;


void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(1000);
  if ((sensorValue >= 1) && (sensorValue <= 200)) {
    digitalWrite(led1, HIGH);
    delay(100);
  } else if ((sensorValue >= 201) && (sensorValue <= 300)) {
    digitalWrite(led2, HIGH);
    delay(100);
  } else if ((sensorValue >= 301)) {
    digitalWrite(led3, HIGH);
    Serial.println("You have reached the maximum");

    digitalWrite(buzzer, HIGH);
  } else if (sensorValue == 0) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
}
