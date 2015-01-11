bool sampleLocked = true;
bool sampleDD = true;
int  sampleRate = 48;
int  sampleBits = 16;

void _blink(int pins[])
{

  static unsigned long previousMillis;
  static int ledState = LOW;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > LED_BLINK_INTERVAL) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    String pinPrefix = "#";
    int count = sizeof(pins);

    for (int i = 0; i < count; i++) {
      int pin = pins[i];
      // set the LED with the ledState of the variable:
      //Serial.println("DAC: Blink " + pinPrefix + pin + "to " + ledState);
      digitalWrite(pin, ledState);
    }

  }
}

void displaySampleRate(int pin44, int pin96, int pin24b)
{
  if (!sampleLocked) {
    digitalWrite(pin44, LOW);
    digitalWrite(pin96, LOW);
    digitalWrite(pin24b, LOW);
  } else if (!sampleDD) {
    if (sampleRate <= 48) {
      digitalWrite(pin44, HIGH);
      digitalWrite(pin96, LOW);
    } else if (sampleRate > 48 && sampleRate < 192) {
      digitalWrite(pin44, LOW);
      digitalWrite(pin96, HIGH);
    } else if (sampleRate >= 192) {
      digitalWrite(pin44, HIGH);
      digitalWrite(pin96, HIGH);
    }
    
    if (sampleBits <= 16) {
      digitalWrite(pin24b, LOW);
    } else {
      digitalWrite(pin24b, HIGH);
    }
  } else {
    digitalWrite(pin44, LOW);
    digitalWrite(pin96, LOW);
    int pins[] = {pin24b};
    _blink(pins);
  }


  //digitalWrite(pin24b, HIGH);
}
