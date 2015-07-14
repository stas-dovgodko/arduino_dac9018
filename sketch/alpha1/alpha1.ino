#include <Wire.h>

#include <EEPROM.h>
#include <Bounce2.h>

Bounce qt_bouncer = Bounce();
Bounce flt_bouncer = Bounce();
Bounce dpll_bouncer = Bounce();



#define headphonesControlPin A1 // headphones pin (should be open for connected HPs )
#define outputRelayPin A3 // output switch relay
#define headphonesPowerRelayPin A2 // output switch relay

//#define DEBUG
//#define RESET
#define USE100MHZ

#define pin_fltFast 2 // !
#define pin_fs44 7 // !
#define pin_DpllLow 3 // !
#define pin_fs192 9 // !
#define pin_fltSlow 4 // !
#define pin_fs96 8 // !
#define pin_qt7 5 // !
#define pin_qt9 6 // !
#define pin_DpllMidH 10 // !
#define pin_DpllOff 11 // !
#define pin_DpllMid 12 // !
#define pin_DpllHigh 13 // !



#define sw_qt 1
#define sw_flt 0
#define sw_dpll A0

String pinPrefix = "#";


const int OUTPUT_TO_HP_POWER_DELAY = 1000; // delay to power off or switch output
const int LED_BLINK_INTERVAL = 1000; // blick interval

const byte OUTPUT_TO_HP = 1;
const byte OUTPUT_TO_AUX = 2;

byte filterNumber = 0;
byte output_mode = OUTPUT_TO_AUX;
bool headphones_power = false;


boolean status_isdsd = false;
boolean status_islock = false;
boolean status_changed = false;
unsigned long status_sr = 0;
byte status_sr_idx = 0;


void setup() {

#ifdef DEBUG
  Serial.begin(9600);
  Serial.println(F("BOOT"));
#else
  Serial.end();
#endif DEBUG


  s_setup();
  leds_setup();

  setupAmp(headphonesPowerRelayPin);
  setupOutputSwitcher(outputRelayPin);
  setupHeadphones(headphonesControlPin);




}

byte filter;
byte dpll;
byte qt;

void loop() {

  s_loop();
  
  if (dpll_bouncer.update() && dpll_bouncer.read() == HIGH) {
    
      if (++dpll > 5) dpll = 0;
      s_setDPLLFilterNumber(dpll);
  }
  
  if (qt_bouncer.update() && qt_bouncer.read() == HIGH) {
      if (++qt > 9) qt = 6;
      s_setQuantizer(qt);
  }
  
  if (flt_bouncer.update() && flt_bouncer.read() == HIGH) {

      if (++filter > 2) filter = (status_sr > 352000) ? 0 : 1; // bypass oversample works only for UH rates

      if (status_isdsd) {
        s_setIirFilter(filter);
        s_setFirFilter(1); // slow (?)
      } else {
        s_setIirFilter(0); // 47
        s_setFirFilter(filter);
      }
  }
  
  leds_displayFilter(filter);
  leds_displayDpll(dpll);
  leds_displayQt(qt);
  
  if (status_islock) {
    if (status_isdsd) {
        leds_displayDSD();
    } else {
      leds_displaySampleRate(status_sr);
    }
  } else {
    leds_displayLostLock();
  }
  
  loopHeadphones();
}
