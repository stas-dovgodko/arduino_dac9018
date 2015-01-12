bool sampleLocked = true;
bool sampleDD = true;
byte  sampleRate = 48;
byte  sampleBits = 16;

//byte filterLed1[16] = {0, 200, 255, 200, 150, 100, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//byte filterLed2[16] = {0, 0, 0, 50, 100, 150, 200, 255, 200, 150, 100, 50, 0, 0, 0, 0};
//byte filterLed3[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 100, 150, 200, 255};

byte filterLed1[16] = {0, 120, 170, 255, 170, 120, 50,  0,   0,   0,   0,   0,   0,  0,   0,   0};
byte filterLed2[16] = {0, 0,   0,   0,   0,   0,   50,  120, 170, 255, 170, 120, 50, 0,   0,   0};
byte filterLed3[16] = {0, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   50, 120, 170, 255};

void setupDac() {
  pinMode(sampleRate44Pin, OUTPUT);
  pinMode(sampleRate96Pin, OUTPUT);
  pinMode(sampleRate24bPin, OUTPUT);
  
  pinMode(filter1Pin, OUTPUT);
  pinMode(filter2Pin, OUTPUT);
  pinMode(filter3Pin, OUTPUT);
  pinMode(filterUpControl, INPUT_PULLUP);
  pinMode(filterDownControl, INPUT_PULLUP);
}

void loopDac() {
  displaySampleRate(sampleRate44Pin, sampleRate96Pin, sampleRate24bPin);
  displayFilter(filter1Pin, filter2Pin, filter3Pin);
  //delay(10);
}


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
}

void displayFilter(int pin1, int pin2, int pin3)
{
  checkFilterControl();
  analogWrite(pin1, filterLed1[filterNumber]);
  analogWrite(pin2, filterLed2[filterNumber]);
  analogWrite(pin3, filterLed3[filterNumber]);
}

int checkFilterControl()
{
  static unsigned long previousMillisUp = 0;
  static unsigned long previousMillisDown = 0;
  
  int upState = digitalRead(filterUpControl);
  int downState = digitalRead(filterDownControl);
  if (downState == HIGH && upState == LOW) {
    if (millis() - previousMillisDown > 100)
    {
      previousMillisDown = millis();
      if (filterNumber < 15) filterNumber++;
    }
  } else {
    previousMillisDown = millis();
  }
  if (downState == LOW && upState == HIGH) {
    if (millis() - previousMillisUp > 100)
    {
      previousMillisUp = millis();
      if (filterNumber > 0) filterNumber--;
    }
  } else {
    previousMillisUp = millis();
  }
  
  return filterNumber;
}
  


