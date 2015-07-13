//#define HP_VOID_STATE 1

boolean waitForInit = true;

boolean waitForHPOutput;
boolean waitForAmpOff;
unsigned long headphonesTimer;

byte pinAmpPower;
byte pinOutputSwitcher;

Bounce headphonesbouncer = Bounce(); 

void setupHeadphones(byte pin) {
  pinMode(pin, INPUT_PULLUP);
  headphonesbouncer.attach( pin );
  headphonesbouncer.interval(200);
}

void setupAmp(byte pin) {
  pinAmpPower = pin;
  pinMode(pinAmpPower, OUTPUT);
}

void setupOutputSwitcher(byte pin) {
  pinOutputSwitcher = pin;
  pinMode(pinOutputSwitcher, OUTPUT);
}

void loopHeadphones() {
  
  boolean changed = headphonesbouncer.update();
  
  #ifdef HP_VOID_STATE
  byte state_on = HIGH;
  byte state_off = LOW;
  #else
  byte state_on = LOW;
  byte state_off = HIGH;
  #endif HP_VOID_STATE
  
  byte state = headphonesbouncer.read();
  
  if ( waitForInit || changed ) {
    waitForHPOutput = false;
    waitForAmpOff = false;
    if (state == state_on) {
      // should power on amp
      // and schedule switch output to hp
      turnOnAmp();
      waitForHPOutput = true;
    } else {
      // should switch output to aux
      // and schedule power off amp
      setOutputMode(OUTPUT_TO_AUX);
      waitForAmpOff = true;
    }
    headphonesTimer = millis();
    if (waitForInit) waitForInit = false;
  }
  
  if ((waitForHPOutput || waitForAmpOff) && millis() - headphonesTimer > OUTPUT_TO_HP_POWER_DELAY) {
     if (waitForHPOutput) {
       setOutputMode(OUTPUT_TO_HP);
       waitForHPOutput = false;
     } else if (waitForAmpOff) {
       turnOffAmp();
       waitForAmpOff = false;
     }
  }
}

void turnOnAmp() {
  
  #ifdef DEBUG
  Serial.println(F("HP: Turn on amp"));
  #endif DEBUG
  
  digitalWrite(pinAmpPower, LOW);
}

void turnOffAmp() {
  #ifdef DEBUG
  Serial.println(F("HP: Turn off amp"));
  #endif DEBUG
  
  digitalWrite(pinAmpPower, HIGH);
}

void setOutputMode(byte mode) {
  if (mode == OUTPUT_TO_AUX) {
    #ifdef DEBUG
    Serial.println(F("HP: Set output to AUX"));
    #endif DEBUG
    
    digitalWrite(pinOutputSwitcher, HIGH);
  } else if (mode == OUTPUT_TO_HP) {
    
    #ifdef DEBUG
    Serial.println(F("HP: Set output to HP"));
    #endif DEBUG
    
    digitalWrite(pinOutputSwitcher, LOW);
  }
}


