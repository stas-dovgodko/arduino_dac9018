#define headphonesControlPin 7 // headphones pin (should be open for connected HPs )
#define outputRelayPin 2 // output switch relay
#define headphonesPowerRelayPin 3 // output switch relay

#define sampleRate44Pin 10
#define sampleRate96Pin 9
#define sampleRate24bPin 8

const int OUTPUT_TO_HP_POWER_DELAY = 1000; // delay to power off or switch output
const int LED_BLINK_INTERVAL = 1000; // blick interval



void setup() {
  Serial.begin(9600);
  
  String pinPrefix = "#";
  
  Serial.println("DEBUG: HP control pin " + pinPrefix + headphonesControlPin);
  Serial.println("DEBUG: Output relay pin " + pinPrefix + outputRelayPin);
  Serial.println("DEBUG: HP amp power relay pin " + pinPrefix + headphonesPowerRelayPin);
  
  pinMode(headphonesControlPin, INPUT_PULLUP);
  pinMode(outputRelayPin, OUTPUT);
  pinMode(headphonesPowerRelayPin, OUTPUT);
  
  pinMode(sampleRate44Pin, OUTPUT);
  pinMode(sampleRate96Pin, OUTPUT);
  pinMode(sampleRate24bPin, OUTPUT);
}

void loop() {
  checkHeaphones(headphonesControlPin, outputRelayPin, headphonesPowerRelayPin);
  displaySampleRate(sampleRate44Pin, sampleRate96Pin, sampleRate24bPin);
}


