// C++ code
//

INT MOTOR_CONTROL = 13


void setup()
{
  pinMode(MOTOR_CONTROL, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

void loop(){
  digitalWrite(MOTOR_CONTROL,HIGH);
  delay(1500);
  digitalWrite`
