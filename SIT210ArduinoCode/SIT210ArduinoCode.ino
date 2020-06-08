/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int led = 11;
int motion = 10;
int mobileSwitch = 9;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(motion, INPUT);
  pinMode(mobileSwitch, INPUT);
  pinMode(led, OUTPUT);
}

void turnLightOn()
{
  digitalWrite(led, HIGH);
}

void turnLightOff()
{
  digitalWrite(led, LOW);
}

// the loop routine runs over and over again forever:
void loop() {

  int motionValue = digitalRead(motion);
  int mobileValue = digitalRead(mobileSwitch);
  Serial.println(motionValue);
  Serial.println(mobileValue);

  if (mobileSwitch != 1)
  {
  if (motionValue == 1)
  {
    turnLightOn();
    int loop = 0;
    while (loop < 300)
    {
      Serial.println("Loop");
      mobileValue = digitalRead(mobileSwitch);
      if (mobileValue == 1)
      {
        Serial.println("Mobile input detected, breaking loop");
        break;
      }
      delay(1000);
      loop++;
    }
  }
  else if (mobileValue == 1)
  {
    turnLightOn();
  }
  else
  {
    turnLightOff();
  }
  }
  delay(1);        // delay in between reads for stability
}
