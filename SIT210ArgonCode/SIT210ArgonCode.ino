int motionPin = D5;
int ledPin = D6;
int mobilePin = D7;

void setup() {
  pinMode(mobilePin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void turnLedOn()
{
    digitalWrite(ledPin, HIGH);
}

void turnLedOff()
{
    digitalWrite(ledPin, LOW);
}

void loop() {
  if (digitalRead(mobilePin) == 1)
  {
      turnLedOn();
  }
  else if (digitalRead(motionPin) == 1)
  {
    turnLedOn();
  }
  else
  {
      turnLedOff();
  }
}

