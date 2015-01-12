const byte OUTPUT_TO_HP = 1;
const byte OUTPUT_TO_AUX = 2;
unsigned long highMillis[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long lowMillis[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte headphonesRelayState[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

boolean checkControlPin(int Pin, int headphonesControlThreashold = 2) {
  
  
  int buttonState;

  buttonState = digitalRead(Pin);

  if (buttonState == HIGH) {
    unsigned long diff = millis() - highMillis[Pin];
    if (diff > 100)
    {
      highMillis[Pin] = millis();
      if (headphonesRelayState[Pin] < 255) headphonesRelayState[Pin]++;
    }
    
  }
  else if (buttonState == LOW) {
    unsigned long diff = millis() - lowMillis[Pin];
    if (diff > 100)
    {
      lowMillis[Pin] = millis();
      headphonesRelayState[Pin] = 0;
    }
  }

Serial.println(headphonesRelayState[Pin]);
  if (headphonesRelayState[Pin] > headphonesControlThreashold) {
    return true;
  } else {
    return false;
  }
}

// this will check headphones aux pin
// and control output stereo relays and headphones amp power with delay
bool checkHeaphones(int pin, int outputPin, int powerPin) {
  static byte output_mode = OUTPUT_TO_AUX;
  static bool headphones_power = false;
  static long headphones_power_init;
  
  bool hp_attached = checkControlPin(pin, 4);

  // check headphones state
  if (hp_attached) {
    if (!headphones_power) {
       headphones_power = true;
       Serial.println(F("HP: Turn on amp"));
       headphones_power_init = millis();
    }
    
    if (output_mode != OUTPUT_TO_HP) {
      if (millis() - headphones_power_init > OUTPUT_TO_HP_POWER_DELAY) {
        output_mode = OUTPUT_TO_HP;
        Serial.println(F("HP: Set output to HP"));
      }
    }
  }
  else {
    if (output_mode != OUTPUT_TO_AUX) {
      output_mode = OUTPUT_TO_AUX;
      Serial.println(F("HP: Set output to AUX"));
      headphones_power_init = millis();
    }
    
    if (headphones_power) {
      if (millis() - headphones_power_init > OUTPUT_TO_HP_POWER_DELAY) {
        headphones_power = false;
        Serial.println(F("HP: Turn off amp"));  
     }
    }
  }
  


  // check hp power
  if (headphones_power) {
    digitalWrite(powerPin, LOW);
  } else {
    digitalWrite(powerPin, HIGH);
  }

  // set output relay
  if (output_mode == OUTPUT_TO_HP) {
    
    digitalWrite(outputPin, LOW);
  } else if (output_mode == OUTPUT_TO_AUX) {
    
    digitalWrite(outputPin, HIGH);
    
  }
  
  return (output_mode == OUTPUT_TO_HP) && headphones_power;
}
