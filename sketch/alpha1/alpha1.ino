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

const int OUTPUT_TO_HP_POWER_DELAY = 1000; // delay to power off or switch output
const int LED_BLINK_INTERVAL = 1000; // blick interval


byte filterNumber = 0;


void setup() {
  Serial.begin(9600);
  Serial.println(F("BOOT"));
  //String pinPrefix = "#";
  
  
  //Serial.println(F("DEBUG: HP control pin ") + pinPrefix + headphonesControlPin);
  //Serial.println("DEBUG: Output relay pin " + pinPrefix + outputRelayPin);
  //Serial.println("DEBUG: HP amp power relay pin " + pinPrefix + headphonesPowerRelayPin);
  
  pinMode(headphonesControlPin, INPUT_PULLUP);
  pinMode(outputRelayPin, OUTPUT);
  pinMode(headphonesPowerRelayPin, OUTPUT);
  
  pinMode(sampleRate44Pin, OUTPUT);
  pinMode(sampleRate96Pin, OUTPUT);
  pinMode(sampleRate24bPin, OUTPUT);
  
  pinMode(filter1Pin, OUTPUT);
  pinMode(filter2Pin, OUTPUT);
  pinMode(filter3Pin, OUTPUT);
  pinMode(filterUpControl, INPUT_PULLUP);
  pinMode(filterDownControl, INPUT_PULLUP);
}

void loop() {
  checkHeaphones(headphonesControlPin, outputRelayPin, headphonesPowerRelayPin);
  displaySampleRate(sampleRate44Pin, sampleRate96Pin, sampleRate24bPin);
  displayFilter(filter1Pin, filter2Pin, filter3Pin);
  //delay(10);
}


