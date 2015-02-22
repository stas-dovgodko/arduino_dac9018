#include <Wire.h>
#include <EEPROM.h>
#include <Bounce2.h>

Bounce qt_bouncer = Bounce();
Bounce flt_bouncer = Bounce();
Bounce dpll_bouncer = Bounce();

unsigned long flt_bouncer_press_timestamp;


#define headphonesControlPin A3 // headphones pin (should be open for connected HPs )
#define outputRelayPin 12 // output switch relay
#define headphonesPowerRelayPin 9 // output switch relay
#define filterUpControl A2
#define filterDownControl A1

#define pin_fs44 10 // !
#define pin_fs96 2 // !

#define pin_fs192 0 // !

#define pin_qt7 4 // !
#define pin_qt9 3 // !
#define pin_fltFast 6 // !
#define pin_fltSlow 11 // !

#define pin_DpllLow 7 // !
#define pin_DpllMid 8 // !
#define pin_DpllMidH 1 // !
#define pin_DpllHigh 5 // !

#define pin_DpllOff 13 // !

#define sw_qt A0
#define sw_flt A2
#define sw_dpll A1

String pinPrefix = "#";


const int OUTPUT_TO_HP_POWER_DELAY = 1000; // delay to power off or switch output
const int LED_BLINK_INTERVAL = 1000; // blick interval

const byte OUTPUT_TO_HP = 1;
const byte OUTPUT_TO_AUX = 2;

byte filterNumber = 0;
byte output_mode = OUTPUT_TO_AUX;
bool headphones_power = false;



void setup() {
  Serial.end();
  leds_setup();
  /*for (int i = 0; i <= 13; i++) {
      digitalWrite(i, HIGH);
      delay(1000);
            digitalWrite(i, LOW);
    }*/
  
  
  Serial.begin(9600);
  //Serial.println(F("BOOT"));
    
  setupAmp(headphonesPowerRelayPin);
  setupOutputSwitcher(outputRelayPin);
  setupHeadphones(headphonesControlPin);
  
  dac_setup();
}
byte dpll = 0;
bool dpll_off = false;
bool pressed_long = false;

void loop() {
byte chipStatus=0;
unsigned long sr = 0; 
  loopHeadphones();  
  
  chipStatus=readRegister(27); // Read status register
  if(chipStatus&B00000001){    // There is a lock in a signal
      sr=sampleRate();           // Get the sample rate from register
      leds_displaySampleRate(sr);
  } else {
      leds_displaySampleRate(0);
  }
  
  byte qt = dac_getQuantizer();
  leds_displayQt(qt);
   
  
  if (qt_bouncer.update() && qt_bouncer.read() == HIGH) {
    qt++; if (qt > 9) qt = 6;
    dac_setQuantizer(qt);
    Serial.println("QT + ");
  }
  
  
  
  byte filter = min(dac_getIirFilter(), dac_getFirFilter());
  leds_displayFilter(filter);
  
  if (flt_bouncer.update() && flt_bouncer.read() == HIGH) {
    
    Serial.print("IIR:");
    Serial.println(dac_getIirFilter());
        Serial.print("FIR:");
        Serial.println(dac_getFirFilter());
    
    filter++; if (filter > 2) filter = 0;
    Serial.print("NEW:");
        Serial.println(filter);
    dac_setIirFilter(filter);
    dac_setFirFilter(filter);
    DumpSabreRegisters();
  }
  
  
  
  unsigned long press_interval;
  
  
  
  if (dpll_bouncer.update()) {
    if ( dpll_bouncer.fell()  ) {
    
      
       flt_bouncer_press_timestamp = millis();
    
    }
    if (dpll_bouncer.read() == HIGH) {
      
      press_interval = millis()-flt_bouncer_press_timestamp;
      
      if (press_interval < 1000) { // long press
            Serial.print("SHORT");
        if (!pressed_long) {
          dpll_off = false;
          dpll++;
          if (dpll > 4) dpll = 0;
          dac_setDPLL(dpll, dpll_off);
          leds_displayDpll(dpll, dpll_off);
        } else {
          pressed_long = false;
        }
      } else {
      }
    }
  } else if (dpll_bouncer.read() == LOW) {
    press_interval = millis()-flt_bouncer_press_timestamp;
    if (press_interval > 1000) {
      Serial.print("LONG");
      flt_bouncer_press_timestamp = millis();
      press_interval = 0;
      pressed_long = true;
      dpll_off = !dpll_off;
      
        dac_setDPLL(dpll, dpll_off);
        leds_displayDpll(dpll, dpll_off);
      
    }
  }
  
  
}


