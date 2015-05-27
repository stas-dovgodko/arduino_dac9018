



void leds_setup() {
  byte leds[12] = {pin_fs44, pin_fs96, pin_fs192, pin_qt7, pin_qt9, pin_fltFast, pin_fltSlow,  pin_DpllLow, pin_DpllMid, pin_DpllMidH, pin_DpllHigh,  pin_DpllOff};

  for (int i = 0; i < 12; i++) {
    byte pin = leds[i];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  
  for (int i = 0; i < 12; i++) {
    byte pin = leds[i];
    digitalWrite(pin, HIGH);
  }

//delay(100000);

  for (int i = 0; i < 12; i++) {
    byte pin = leds[i];
    digitalWrite(pin, LOW);  digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
  }

  pinMode(sw_qt, INPUT_PULLUP);
  qt_bouncer.attach( sw_qt );
  qt_bouncer.interval(50);

  pinMode(sw_flt, INPUT_PULLUP);
  flt_bouncer.attach( sw_flt );
  flt_bouncer.interval(50);

  pinMode(sw_dpll, INPUT_PULLUP);
  dpll_bouncer.attach( sw_dpll );
  dpll_bouncer.interval(50);
}

void leds_displaySampleRate(unsigned long sr) {
  if (sr <= 0) {
    digitalWrite(pin_fs44, LOW);
    digitalWrite(pin_fs96, LOW);
    digitalWrite(pin_fs192, LOW);
  } else if (sr <= 45000) {
    // 44
    digitalWrite(pin_fs44, HIGH);
    digitalWrite(pin_fs96, LOW);
    digitalWrite(pin_fs192, LOW);
  } else if (sr <= 89000) {
    // 88
    digitalWrite(pin_fs44, HIGH);
    digitalWrite(pin_fs96, HIGH);
    digitalWrite(pin_fs192, LOW);
  } else if (sr <= 99000) {
    // 96
    digitalWrite(pin_fs44, LOW);
    digitalWrite(pin_fs96, HIGH);
    digitalWrite(pin_fs192, LOW);
  } else if (sr <= 400000) {
    // 192
    digitalWrite(pin_fs44, LOW);
    digitalWrite(pin_fs96, LOW);
    digitalWrite(pin_fs192, HIGH);
  } else {
    // DSD
    digitalWrite(pin_fs44, HIGH);
    digitalWrite(pin_fs96, HIGH);
    digitalWrite(pin_fs192, HIGH);
  }
}

void leds_displayQt(byte value) {
  switch (value)
  {
    case 6:
      digitalWrite(pin_qt7, LOW);
      digitalWrite(pin_qt9, LOW);
      break;

    case 7:
      digitalWrite(pin_qt7, HIGH);
      digitalWrite(pin_qt9, LOW);
      break;

    case 8:
      digitalWrite(pin_qt7, HIGH);
      digitalWrite(pin_qt9, HIGH);
      break;

    case 9:
      digitalWrite(pin_qt7, LOW);
      digitalWrite(pin_qt9, HIGH);
      break;
  }
}

void leds_displayFilter(byte value) {
  if (value == 0) { // bypass
    digitalWrite(pin_fltFast, LOW);
    digitalWrite(pin_fltSlow, LOW);
  } else if (value == 1) {
    digitalWrite(pin_fltFast, HIGH);
    digitalWrite(pin_fltSlow, LOW);
  } else if (value == 2) {
    digitalWrite(pin_fltFast, LOW);
    digitalWrite(pin_fltSlow, HIGH);
  }
}

void leds_displayDpll(byte value, boolean dpll_off) {
  
  Serial.println(value);
  
  if (value == 0) { // default
    digitalWrite(pin_DpllLow, LOW);
    digitalWrite(pin_DpllMid, LOW);
    digitalWrite(pin_DpllMidH, LOW);
    digitalWrite(pin_DpllHigh, LOW);
    digitalWrite(pin_DpllOff, LOW);
  } else if (value == 1) {
    digitalWrite(pin_DpllLow, HIGH);
    digitalWrite(pin_DpllMid, LOW);
    digitalWrite(pin_DpllMidH, LOW);
    digitalWrite(pin_DpllHigh, LOW);
    digitalWrite(pin_DpllOff, LOW);
  } else if (value == 2) {
    digitalWrite(pin_DpllLow, LOW);
    digitalWrite(pin_DpllMid, HIGH);
    digitalWrite(pin_DpllMidH, LOW);
    digitalWrite(pin_DpllHigh, LOW);
    digitalWrite(pin_DpllOff, LOW);
  } else if (value == 3) {
    digitalWrite(pin_DpllLow, LOW);
    digitalWrite(pin_DpllMid, LOW);
    digitalWrite(pin_DpllMidH, HIGH);
    digitalWrite(pin_DpllHigh, LOW);
    digitalWrite(pin_DpllOff, LOW);
  } else if (value == 4) {
    digitalWrite(pin_DpllLow, LOW);
    digitalWrite(pin_DpllMid, LOW);
    digitalWrite(pin_DpllMidH, LOW);
    digitalWrite(pin_DpllHigh, HIGH);
    digitalWrite(pin_DpllOff, LOW);
  } else if (value == 10) {
    digitalWrite(pin_DpllLow, LOW);
    digitalWrite(pin_DpllMid, LOW);
    digitalWrite(pin_DpllMidH, LOW);
    digitalWrite(pin_DpllHigh, LOW);
    digitalWrite(pin_DpllOff, HIGH);
  }
}

void leds_loop() {

  //boolean changed = headphonesbouncer.update();

  //byte state = headphonesbouncer.read();


}
