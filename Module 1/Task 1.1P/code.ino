void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  int sensorReading = analogRead(A1);
  
  float voltage = sensorReading * (5000 / 1024.0);
  int temperature = (voltage - 500) / 10;
  
  if (temperature > 40 && digitalRead(13) == LOW) {
    digitalWrite(13, HIGH);
    Serial.println("Temperature exceeded 40 degrees!");
  }
  
  else if (temperature <= 40 && digitalRead(13) == HIGH) {
    digitalWrite(13, LOW);
    Serial.println("Temperature lowered to 40 degrees!");
  }
}