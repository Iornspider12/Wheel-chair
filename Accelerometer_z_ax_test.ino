int z;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);

}

void loop()
{
  z = analogRead(A0);

  Serial.print("z: ");
  Serial.println(z);
  delay(200);

}
