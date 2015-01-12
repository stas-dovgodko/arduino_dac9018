#include <Bounce2.h>

#define headphonesControlPin 4 // headphones pin (should be open for connected HPs )
#define outputRelayPin 2 // output switch relay
#define headphonesPowerRelayPin 3 // output switch relay

#define sampleRate44Pin 13
#define sampleRate96Pin 12
#define sampleRate24bPin 8

#define filter1Pin 9
#define filter2Pin 10
#define filter3Pin 11

#define filterUpControl A2
#define filterDownControl A1

String pinPrefix = "#";


const int OUTPUT_TO_HP_POWER_DELAY = 1000; // delay to power off or switch output
const int LED_BLINK_INTERVAL = 1000; // blick interval

const byte OUTPUT_TO_HP = 1;
const byte OUTPUT_TO_AUX = 2;

byte filterNumber = 0;
byte output_mode = OUTPUT_TO_AUX;
bool headphones_power = false;



void setup() {
  Serial.begin(9600);
  Serial.println(F("BOOT"));
    
  setupAmp(headphonesPowerRelayPin);
  setupOutputSwitcher(outputRelayPin);
  setupHeadphones(headphonesControlPin);
  
  setupDac();
}

void loop() {

  loopHeadphones();  
  
  loopDac();
}


