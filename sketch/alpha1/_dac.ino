
//#define USE80MHZ
#define USE100MHZ

#define STEREO
//#define DUALMONO

//#define DEFAULTATTNU 0x14 // -10
#define DEFAULTATTNU 0x00 // -10
//-50 dB this is 50x2=100 or 0x64. Sabre32 is 0 to -127dB in .5dB steps
#define MAXATTNU 0xC6     //-99dB this is 99X2=198 or 0xC6 -Can go higher but LCD shows 2 digits
#define MINATTNU 0x00     //-0 dB -Maximum volume is -0 dB
#define DIM 0x8C          //-70 dB this is 70x2=140 or 0x8C. Dim volume a kind of soft mute
#define RAMP 10           // Additional msec delay per 1 db for ramping up to volume after dim

#define FORMATVAL 0
#define FIRVAL 1
#define IIRVAL 2
#define I2SDPLLVAL 3
#define DSDDPLLVAL 4
#define DEEMVAL 5
#define BALVAL 6

#define ICHO 6
#define FORMATCHO 5   // ?? SPDIF, I2S/DSD, etc.
#define FIRCHO 4      // Fast, slow, minimum, bypass
#define IIRCHO 5      // 47k, 50k, 60k, 70k, bypass
#define I2SDPLLCHO 16 // Lowest to Highest, OFF: 16 values
#define DSDDPLLCHO 16 // Lowest to Highest, OFF: 16 values
#define DEEMCHO 6     // Off, auto, 32k, 44k and 48k and "reserved"
#define BALCHO 39     // 39 possible values for balance settings
// There is one more: ICHO which is already defined above in the customization section.
// Choices SRF are two, so we just use a toggle variable and not remembered.
// Vol selection is seprate and not remembered.

#define MAXPARAM 8  // ?





// NEW
byte reg10;						 // jitter ON, DACs Unmute, other defaults (0xFE also I2S)
byte reg14;						 // Default value for register 14. We use a variable for reg 14 because it controls
byte reg25;						 // 0= allow all settings
byte reg17;
byte reg17R;
byte IirFilterVal;
// NEW











boolean SRExact = true;  // Display exact sample rate value; false = display nominal value

/*
 The array that holds the parameters for each input. The size of the array is the number of inputs
 multiplied by the number of parameters (each input definition remembers its own parameter settings).
 The current input selection is recorded after each change into the array in the eeprom)
*/
byte settings[ICHO][MAXPARAM];  // Array to hold parameter values

byte input = 0;
byte currAttnu = MINATTNU; // Variable to hold the current attenuation value
byte lBal = 0;
byte rBal = 0;
byte chipStatus = 0;     // To hold the value of chip status register
unsigned long sr = 0;              // Holds the value for the incoming sample rate



void dac_setup() {


  Wire.begin();        // Join the I2C bus as a master
  
  SetSabreRegistersToDefaults();
  muteDacs();


  reg14 = 0xFD; // Default value for register 14. We use a variable for reg 14 because it controls

  // several parameters: IIR, FIR, differential whereas the other registers typically
  // controls a single parameter.
  reg25 = 0;  // 0= allow all settings
  reg17 = 0x9C; // Auto SPDIF, 8-channel mode, other defaults
  reg10 = 0xCE;		   // jitter ON, dacs unmute, other defaults (0xFE also I2S)


  byte input = 0;               // The current input to the DAC


  // Reg 0 to Reg 7 Set volume registers with startup volume level
  //writeSabreReg(0x0D,0x00);     // DAC in-phase
  //writeSabreReg(0x13,0x00);     // DACB anti-phase
  //writeSabreReg(0x25,0x00);     // Use built in filter for stage 1 and stage 2
  //writeSabreReg(0x0E,reg14);    // Reg 14: BuffII input map, trueDiff, normal IIR and Fast roll off



  reg25 = 0x02;
  //writeSabreReg(0x19, reg25);     // DPLL Mode control:  Allow all DPLL settings at 128x: 00000000 or 0x01

  //writeSabreReg(0x0B, 0x85);      // Reg 11: Set DPLL bandwidth to lowest

  // 0xF9 Default for BII wiring, true differential, IIR normal, FIR fast
  //writeSabreReg(0x0F, 0xAA);      // 8-bit quantizer

  //writeSabreReg(0x0C, 0x20);		// Register 12 (0x0C): Set no notch delay

  reg10 = 0xCF;
  writeSabreReg(0x0A, reg10);  // 11001111 or 0xCF (Jitter on, etc, MUTE DACs)
  //bitSet(reg10, 0);              // Set bit zero for reg 10: Mute DACs
  //writeSabreReg(0x0A, reg10);    // Mute DACs. Earliest we can mute the DACs to avoid full volume

  reg17 = B00010100;
  writeSabreReg(0x11, reg17);		// Register 17 (0x11) (MC5):  Auto SPDIF, others at defaults: 0x1C

  writeSabreReg(0x08, B11111111);      // Register 8 (0x08) Auto-mute level, manual spdif/i2s

  writeSabreReg(0x12, 0x00);      // Set SPDIF to input #0

  /*
          // Set SPDIF to input #1
  			// Move the spdif mux away from a live spdif signal
  			//bitClear(reg17,3);               // Reg 17: manual SPDIF -Clear bit 3
  			writeSabreReg(0x11,reg17);       // Reg 17: Auto spdif detection OFF
  			//writeSabreReg(0x08,0x68);        // Reg 8: Enable I2S/DSD input format
  			spdifIn=false;                   // Set variable to indicate input format is I2S/DSD mode

  			bitSet(reg10,5);                 // Set to right justified format
  			bitClear(reg10,4);
  			bitSet(reg10,6);                 // Set to 32 bit
  			bitSet(reg10,7);
  			writeSabreReg(0x0A,reg10);
  */
  //writeSabreReg(0x12, 0x00);      // Set SPDIF to input #0

  writeSabreReg(0x01, 0x00);
  writeSabreReg(0x02, 0x00);
  writeSabreReg(0x03, 0x00);
  writeSabreReg(0x04, 0x00);
  writeSabreReg(0x05, 0x00);
  writeSabreReg(0x06, 0x00);

  /*
  The code below may provide some mitigation to the white noise during silence
  #ifdef USE80MHZ
  writeSabreReg(0x10,0x08);     // Reg 16: Turn automute loopback -only to mitigate 352.8KHz noise
  writeSabreReg(0x09,0x10);     // Reg 9: Set automute time 4x less than default (value is in denom.)
  #endif USE80MHZ
  */

  //#ifdef DUALMONO                // DAC registers default to stereo. Set to MONO L/R for dual MONO
  //bitSet(reg17,0);               // Set for MONO
  //writeSabreReg(0x11,reg17);     // Sets both chips to MONO
  //#endif DUALMONO
  //
  //#ifdef TPAPHASE
  ///* The outputs on each side of each MONO board will be in opposite phase. In order to do this
  //the phase of the odd dacs are out of phase with the even dacs. Further, buffalo is configured
  //such that (In dual mono mode) the channel on the DAC which is opposite of the selected channel
  //carries the same analog signal but in anti-phase (odd dacs are the left channel;
  //even dacs are the right channel)
  //See http://hifiduino.wordpress.com/sabre32/ for further explaination
  //*/
  //writeSabreLeftReg(0x0D,0x22);  // MONO LEFT DACx: odd dacs=in-phase; even dacs=anti-phase
  //// writeSabreLeftReg(0x13,0x00);  // MONO LEFT DACBx: all dacs anti-phase with respect to DACx
  //writeSabreRightReg(0x0D,0x11); // MONO RIGHT DACx: odd dacs=anti-phase; even dacs=in-phase
  //// writeSabreRightReg(0x13,0x00); // MONO RIGHT DACBx: all dacs anti-phase with respect to DACx
  //#endif TPAPHASE

  chipStatus = readRegister(27);                  // Read chip status register

  dac_setQuantizer(8);

  //muteDacs();
  setSabreVolume(DEFAULTATTNU);
  //writeSabreReg(0x08, 0x7F);
  writeSabreReg(0x0C, 0x20); // notch
  writeSabreReg(0x08, B01111111);
  unmuteDacs();




  //delay(4000);

  //startDac2();  // prints all the DAC settings in the screen; reprogram volume level which will
  // help prevent the potential startup at full volume that happens if the code
  // executes before the registers of the DAC are ready to accept data.
  // This does not catch the case where the DAC is restarted/reset without restarting
  // Arduino. This case should be prevented.
}

void dac_loop() {
  

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





///////////////////////////////////

//byte reg0=0x00;  // System settings. Default value of register 0
//byte reg4=0x00;  // Automute time. Default = disabled
//byte reg5=0x68;  // Automute level. Default is some level, but in reg4 default has automute disabled
//byte reg7=0x80;  // General settings. Default value fast fir, pcm iir and unmuted
//byte reg8=0x81;  // GPIO configuration. GPIO1 set to DPLL Lock; GPIO2 set to input (for SPDIF)
//byte reg10=0x05; // Master Mode Control. Default value: master mode off
//byte reg12=0x5A; // DPLL Settings. Default= one level above lowest for I2S and two levels above
// mid setting for DSD
//byte reg14=0x8A; // Soft Start Settings
//byte reg21=0x00; // Oversampling filter setting and GPIO settings. Default: oversampling ON
// reg11 will need a R and V variable in order to support MONO
byte reg11S = 0x02; // Channel Mapping. "S" means stereo
// Default stereo is Ch1=left, Ch2=right
byte reg11L = 0x00; // Default value for MONO LEFT
byte reg11R = 0x03; // Defuult value for MONO RIGHT
byte reg66 = 0;
byte reg67 = 0;
byte reg68 = 0;
byte reg69 = 0;

volatile unsigned long DPLLNum; // Variable to hold DPLL value

byte readRegister(byte regAddr) {
  Wire.beginTransmission(0x48); // Hard coded the Sabre device address
  Wire.write(regAddr);          // Queues the address of the register
  Wire.endTransmission();       // Sends the address of the register
  Wire.requestFrom(0x48, 1);    // Hard coded to device, request one byte from address
  // specified with Wire.write()/wire.endTransmission()
  //while(!Wire.available()) {  // Wait for byte to be available on the bus
  if (Wire.available()) {         // Wire.available indicates if data is available
    return Wire.read();         // Wire.read() reads the data on the wire
  } else {
    return 0;                   // In no data in the wire, then return 0 to indicate error
  }
  //}                             // Zero is valid error because the ID register for K2M is not 0
}

unsigned long sampleRate() {


  DPLLNum = 0;

  // Reading the 4 registers of DPLL one byte at a time and stuffing into a single 32-bit number
  DPLLNum |= readRegister(31);
  DPLLNum <<= 8;
  DPLLNum |= readRegister(30);
  DPLLNum <<= 8;
  DPLLNum |= readRegister(29);
  DPLLNum <<= 8;
  DPLLNum |= readRegister(28);

  // Different calculation for SPDIF and I2S
#ifdef USE80MHZ
  DPLLNum /= 3436;  // Calculate SR for I2S -80MHz part
#endif
#ifdef USE100MHZ
  DPLLNum *= 4;    // Calculate SR for I2S -100MHz part
  DPLLNum /= 10995; // Calculate SR for I2S -100MHz part
#endif


  if (DPLLNum < 90000) // Adjusting because in integer operation, the residual is truncated
    DPLLNum += 1;
  else if (DPLLNum < 190000)
    DPLLNum += 2;
  else if (DPLLNum < 350000)
    DPLLNum += 3;
  else
    DPLLNum += 4;

  byte val17 = readRegister(17);

  if (bitRead(val17, 6) == 1) { // When OSF is bypassed, the magnitude of DPLL is reduced by a factor of 64
    DPLLNum *= 64;
  }


  return DPLLNum;


}




void muteDacs() {
  byte reg10 = readRegister(10);
  
  bitSet(reg10, 0);              // Set bit zero for reg 10: Mute DACs
  writeSabreReg(0x0A, reg10);    // Mute DACs. Earliest we can mute the DACs to avoid full volume
}

void unmuteDacs() {
  byte reg10 = readRegister(10);
  
  bitClear(reg10, 0);                 // Clear bit zero of reg 10: unmute DACs
  writeSabreReg(0x0A, reg10);         // Unmute DACs
}

// Chip addresses are hardcoded. The default mode for the address 0x48 is for be the left chip

void writeSabreLeftReg(byte regAddr, byte regVal)
{
  Wire.beginTransmission(0x48); // Hard coded to the the DAC device address for stereo
  // or mono left. For stereo same as writeSabreReg()
  Wire.write(regAddr);          // Specifying the address of register
  Wire.write(regVal);           // Writing the value into the register
  Wire.endTransmission();
}

// In dual mono, sometimes different values are written to L and R chips so here is the routine
// to write to registers for the "right" DAC.

#ifdef DUALMONO
void writeSabreRightReg(byte regAddr, byte regVal)
{
  Wire.beginTransmission(0x49); //Hard coded to the the ESS DAC device address
  Wire.write(regAddr); // Specifying the address of register
  Wire.write(regVal); // Writing the value into the register
  Wire.endTransmission();
}
#endif

// The following routine writes to both chips in dual mono mode. With some exceptions, one only needs
// to set one of the chips to be the right channel after all registers are modified.

void writeSabreReg(byte regAddr, byte regVal)
{
  // By default the chip with addres 0x48 is the left channel
  writeSabreLeftReg(regAddr, regVal);

#ifdef DUALMONO
  // If dual mono write also to the other chip.
  writeSabreRightReg(regAddr, regVal);
  // Set the right chip (addr 0x49) to be the right channel
  reg17R = reg17;
  writeSabreRightReg(0x11, bitSet(reg17R, 7));
#endif DUALMONO
}

void setSabreVolume(byte regVal)
{
  currAttnu = regVal;
  writeSabreReg(0, regVal); // set up volume in DAC1
  writeSabreReg(1, regVal); // set up volume in DAC2
  writeSabreReg(2, regVal); // set up volume in DAC3
  writeSabreReg(3, regVal); // set up volume in DAC4
  writeSabreReg(4, regVal); // set up volume in DAC5
  writeSabreReg(5, regVal); // set up volume in DAC6
  writeSabreReg(6, regVal); // set up volume in DAC7
  writeSabreReg(7, regVal); // set up volume in DAC8
}

void readSettings() {
  for (byte i = 0; i < ICHO; i++) {
    for (byte j = 0; j < MAXPARAM; j++) {
      settings[i][j] = EEPROM.read((i * MAXPARAM) + j);

      Serial.println(i * 10000 + j * 100 + 1);
    }
  }
  input = EEPROM.read(ICHO * MAXPARAM);  // Read the last saved input setting
  SRExact = EEPROM.read(ICHO * MAXPARAM + 1); // Read the last saved setting for SRExact
}





byte dac_getQuantizer()
{
  byte valQt = readRegister(15);

  switch (valQt)
  {
    case 0x00:
      return 6;

    case 0x55:
      {
        return 7;
      }

    case 0xAA:
      {
        return 8;
      }

    case 0xFF:
      return 9;
  }
}



void dac_setQuantizer(byte value)
{
  reg14 = readRegister(14);
  switch (value)
  {
    case 6:
      bitSet(reg14, 3);           // True diff
      writeSabreReg(0x0F, 0x00);     // 6-bit quantizer
      break;

    case 7:
      bitSet(reg14, 3);           // True diff
      writeSabreReg(0x0F, 0x55);     // 7-bit quantizer
      break;

    case 8:
      bitSet(reg14, 3);           // True diff
      writeSabreReg(0x0F, 0xAA);    // 8-bit quantizer
      break;

    case 9:
      bitClear(reg14, 3);           // Pseudo diff

      writeSabreReg(0x0F, 0xFF);    // 9-bit quantizer
      break;
  }
  writeSabreReg(0x0E, reg14);
  dac_relock();
}






void DumpSabreRegisters()
{
  Serial.println("");
  Serial.println("Dumping Sabre Registers *********************************");

  byte valReg14 = readRegister(14);
  Serial.print("reg14: 0X" );
  Serial.print(valReg14, HEX);
  Serial.print("   " );
  Serial.println(valReg14, BIN);

  byte valReg10 = readRegister(10);
  Serial.print("reg10: 0X" );
  Serial.print(valReg10, HEX);
  Serial.print("   " );
  Serial.println(valReg10, BIN);

  byte valReg25 = readRegister(25);
  Serial.print("reg25: 0X" );
  Serial.print(valReg25, HEX);
  Serial.print("   " );
  Serial.println(valReg25, BIN);

  byte valReg11 = readRegister(11);
  Serial.print("reg11: 0X" );
  Serial.print(valReg11, HEX);
  Serial.print("   " );
  Serial.println(valReg11, BIN);

  byte valReg17 = readRegister(17);
  Serial.print("reg17: 0X" );
  Serial.print(valReg17, HEX);
  Serial.print("   " );
  Serial.println(valReg17, BIN);

  byte valReg8 = readRegister(8);
  Serial.print("reg8:  0X" );
  Serial.print(valReg8, HEX);
  Serial.print("   " );
  Serial.println(valReg8, BIN);

  byte valReg18 = readRegister(18);
  Serial.print("reg18: 0X" );
  Serial.print(valReg18, HEX);
  Serial.print("   " );
  Serial.println(valReg18, BIN);

  byte valReg37 = readRegister(37);
  Serial.print("reg37: 0X" );
  Serial.print(valReg37, HEX);
  Serial.print("   " );
  Serial.println(valReg37, BIN);

  byte valReg15 = readRegister(15);
  Serial.print("reg15: 0X" );
  Serial.print(valReg15, HEX);
  Serial.print("   " );
  Serial.println(valReg15, BIN);

  byte valReg13 = readRegister(13);
  Serial.print("reg13: 0X" );
  Serial.print(valReg13, HEX);
  Serial.print("   " );
  Serial.println(valReg13, BIN);

  byte valReg19 = readRegister(19);
  Serial.print("reg19: 0X" );
  Serial.print(valReg19, HEX);
  Serial.print("   " );
  Serial.println(valReg19, BIN);

  byte valReg12 = readRegister(12);
  Serial.print("reg12: 0X" );
  Serial.print(valReg12, HEX);
  Serial.print("   " );
  Serial.println(valReg12, BIN);

  byte valReg27 = readRegister(27);
  Serial.print("reg27: 0X" );
  Serial.print(valReg27, HEX);
  Serial.print("   " );
  Serial.print(valReg27, BIN);
  Serial.println(" - Status Register");

  Serial.println("*********************************************************");
}

void dac_setIirFilter(byte value)
{
  reg14 = readRegister(14);
  switch (value)
  {
    case 0:	// PCM						// | | | | | |0|0| | IIR Bandwidth: Normal (for PCM)
      bitClear(reg14, 1);				// Clear bit 1
      bitClear(reg14, 2);				// Clear bit 2
      break;

    case 1:                        // | | | | | |0|1| | IIR Bandwidth: 50k (for DSD) (D)
      bitSet(reg14, 1);               // Set bit 1
      bitClear(reg14, 2);             // Clear bit 2

      break;

    case 2:                      // | | | | | |1|1| | IIR Bandwidth: 70k (for DSD)
      bitSet(reg14, 1);				// Set bit 1
      bitSet(reg14, 2);				// Set bit 2
      break;
  }
  writeSabreReg(0x0E, reg14);
}

void dac_setFirFilter(byte value)
{
  reg14 = readRegister(14);
  reg17 = readRegister(17);

  if (value == 2) {
    bitClear(reg17, 6);
    bitSet(reg14, 0);           // Set bit 0 of reg 14 for sharp fir
  } else if (value == 1) {
    bitClear(reg17, 6);
    bitClear(reg14, 0);         // Clear bit 0 of reg 14 for slow fir
  } else {
    bitSet(reg17, 6);
  }
  writeSabreReg(0x11, reg17);
  writeSabreReg(0x0E, reg14);

}

byte dac_getIirFilter()
{
  reg14 = readRegister(14);

  if (bitRead(reg14, 2) == 1 && bitRead(reg14, 1) == 1) {
    return 2;
  } else if (bitRead(reg14, 2) == 1 && bitRead(reg14, 1) == 0) {
    return 1;
  } else if (bitRead(reg14, 2) == 0 && bitRead(reg14, 1) == 1) {
    return 1;
  } else {
    return 0;
  }


}

byte dac_getFirFilter()
{
  byte val14 = readRegister(14);
  byte val17 = readRegister(17);

  if (bitRead(val17, 6) == 1) {
    return 0;
  } else {

    if (bitRead(val14, 0) == 1) {
      return 2;
    } else {
      return 1;
    }
  }
}


void dac_relock()
{
  byte reg17 = readRegister(17);
	bitSet (reg17,5);                // Reg 17: set Jitter lock bit, normal operation
	writeSabreReg(0x11,reg17);       // Reg 17: bypass OSF on, force relock
	delay(50);
	bitClear(reg17,5);               // Reg 17: clear relock jitter for normal operation
	writeSabreReg(0x11,reg17);       // Reg 17: Jitter eliminator Normal operation

} 

void dac_setDPLL(byte value, bool jitter_reduction_bypass)
{
  byte reg25 = readRegister(25);
  byte reg10 = readRegister(10);
  
  bitClear(reg25, 0); //  for sure
  bitSet(reg10, 3);
  if (!jitter_reduction_bypass) {
    bitSet(reg10, 2); // for sure
  } else {
    bitClear(reg10, 2);        // Clear bit 2 of reg 10: jitter reduction bypass
  }
  
  switch (value)
  {
    case 0:
      bitSet(reg25, 1);           // Reg 25: set bit 1 for "use best dpll"
      break;

    case 1:
      bitClear(reg25, 1);         // Reg 25: Clear bit 1 for "use all settings"
      writeSabreReg(0x0B, 0x89);  // Reg 11: Set corresponding DPLL bandwidth
      break;


    case 2:
      bitClear(reg25, 1);         // Reg 25: Clear bit 1 for "use all settings"
      writeSabreReg(0x0B, 0x91);  // Reg 11: Set corresponding DPLL bandwidth
      break;

    case 3:
      bitClear(reg25, 1);         // Reg 25: Clear bit 1 for "use all settings"
      writeSabreReg(0x0B, 0x95);  // Reg 11: Set corresponding DPLL bandwidth
      break;

    case 4:
      bitClear(reg25, 1);         // Reg 25: Clear bit 1 for "use all settings"
      writeSabreReg(0x0B, 0x9D);  // Reg 11: Set corresponding DPLL bandwidth
      break;
  }

Serial.println("25:");
Serial.println(reg25, BIN);
Serial.println("10:");
Serial.println(reg10, BIN);


  writeSabreReg(0x19, reg25); // Write value into reg 25 for best dpll
  writeSabreReg(0x0A, reg10); // Write JT state
  dac_relock();
}


void SetSabreRegistersToDefaults()
{
  reg10 = 0xCF;
  writeSabreReg(0x0A, reg10);     // 11001111 or 0xCF (Jitter on, etc, MUTE DACs)

  reg25 = 0x02;
  writeSabreReg(0x19, reg25);     // DPLL Mode control:  Allow all DPLL settings at 128x: 00000000 or 0x01

  writeSabreReg(0x0B, 0x85);      // Reg 11: Set DPLL bandwidth to lowest

  reg14 = 0xF8;
  writeSabreReg(0x0E, reg14);		// Register 14 (0x0E) DAC source, IIR Bandwidth and FIR roll off:
  // 0xF9 Default for BII wiring, true differential, IIR normal, FIR fast
  writeSabreReg(0x0F, 0xAA);      // 8-bit quantizer

  writeSabreReg(0x0C, 0x20);		// Register 12 (0x0C): Set no notch delay

  //reg17 = 0x1C;
  //writeSabreReg(0x11, reg17);	// Register 17 (0x11) (MC5):  Auto SPDIF, others at defaults: 0x1C

  reg17 = 0x1C;
  writeSabreReg(0x11, reg17);		// Register 17 (0x11) (MC5):  Auto SPDIF, others at defaults: 0x1C

  writeSabreReg(0x08, 0x7F);      // Register 8 (0x08) Auto-mute level, manual spdif/i2s

  //writeSabreReg(0x12, 0x00);      // Set SPDIF to input #0

  writeSabreReg(0x01, 0x00);
  writeSabreReg(0x02, 0x00);
  writeSabreReg(0x03, 0x00);
  writeSabreReg(0x04, 0x00);
  writeSabreReg(0x05, 0x00);
  writeSabreReg(0x06, 0x00);


  // master trim
  writeSabreReg(0x17, 0x1F); // 00011111 (-12db)
  writeSabreReg(0x16, 0xFF);
  writeSabreReg(0x15, 0xFF);
  writeSabreReg(0x4, 0xFF);
}








