// Master trims tables
const static byte mastertrim[121][4] = {
  {B01111111,B11111111,B11111111,B11111111}, // -0.00db (1.000 times)
  {B01111110,B10001000,B11110110,B00001000}, // -0.10db (1.011 times)
  {B01111101,B00010110,B00110110,B11101110}, // -0.20db (1.023 times)
  {B01111011,B10100111,B10110110,B00011101}, // -0.30db (1.035 times)
  {B01111010,B00111101,B01100111,B00100101}, // -0.40db (1.047 times)
  {B01111000,B11010111,B00111101,B10111110}, // -0.50db (1.059 times)
  {B01110111,B01110101,B00101101,B10111111}, // -0.60db (1.071 times)
  {B01110110,B00010111,B00101011,B00100111}, // -0.70db (1.083 times)
  {B01110100,B10111101,B00101010,B00010101}, // -0.80db (1.096 times)
  {B01110011,B01100111,B00011110,B11001110}, // -0.90db (1.109 times)
  {B01110010,B00010100,B11111101,B10110111}, // -1.00db (1.122 times)
  {B01110000,B11000110,B10111011,B01010110}, // -1.10db (1.134 times)
  {B01101111,B01111100,B01001100,B01010110}, // -1.20db (1.148 times)
  {B01101110,B00110101,B10100101,B10000001}, // -1.30db (1.161 times)
  {B01101100,B11110010,B10111011,B11000010}, // -1.40db (1.174 times)
  {B01101011,B10110011,B10000100,B00100110}, // -1.50db (1.188 times)
  {B01101010,B01110111,B11110011,B11010110}, // -1.60db (1.202 times)
  {B01101001,B01000000,B00000000,B00100001}, // -1.70db (1.216 times)
  {B01101000,B00001011,B10011110,B01101111}, // -1.80db (1.230 times)
  {B01100110,B11011010,B11000100,B01001100}, // -1.90db (1.244 times)
  {B01100101,B10101101,B01100111,B01100000}, // -2.00db (1.258 times)
  {B01100100,B10000011,B01111101,B01110001}, // -2.10db (1.273 times)
  {B01100011,B01011100,B11111100,B01100101}, // -2.20db (1.288 times)
  {B01100010,B00111001,B11011010,B00111101}, // -2.30db (1.303 times)
  {B01100001,B00011010,B00001101,B00011011}, // -2.40db (1.318 times)
  {B01011111,B11111101,B10001011,B00111010}, // -2.50db (1.333 times)
  {B01011110,B11100100,B01001010,B11110011}, // -2.60db (1.348 times)
  {B01011101,B11001110,B01000010,B10111101}, // -2.70db (1.364 times)
  {B01011100,B10111011,B01101001,B00101000}, // -2.80db (1.380 times)
  {B01011011,B10101011,B10110100,B11100010}, // -2.90db (1.396 times)
  {B01011010,B10011111,B00011100,B10110100}, // -3.00db (1.412 times)
  {B01011001,B10010101,B10010111,B10000000}, // -3.10db (1.428 times)
  {B01011000,B10001111,B00011100,B01000101}, // -3.20db (1.445 times)
  {B01010111,B10001011,B10100010,B00011100}, // -3.30db (1.462 times)
  {B01010110,B10001011,B00100000,B00110111}, // -3.40db (1.479 times)
  {B01010101,B10001101,B10001101,B11100010}, // -3.50db (1.496 times)
  {B01010100,B10010010,B11100010,B10000100}, // -3.60db (1.513 times)
  {B01010011,B10011011,B00010101,B10011011}, // -3.70db (1.530 times)
  {B01010010,B10100110,B00011110,B11000000}, // -3.80db (1.548 times)
  {B01010001,B10110011,B11110101,B10100011}, // -3.90db (1.566 times)
  {B01010000,B11000100,B10010010,B00001101}, // -4.00db (1.584 times)
  {B01001111,B11010111,B11101011,B11100000}, // -4.10db (1.603 times)
  {B01001110,B11101101,B11111011,B00010100}, // -4.20db (1.621 times)
  {B01001110,B00000110,B10110111,B10111010}, // -4.30db (1.640 times)
  {B01001101,B00100010,B00011001,B11111001}, // -4.40db (1.659 times)
  {B01001100,B01000000,B00011010,B00010000}, // -4.50db (1.678 times)
  {B01001011,B01100000,B10110000,B01010101}, // -4.60db (1.698 times)
  {B01001010,B10000011,B11010101,B00110010}, // -4.70db (1.717 times)
  {B01001001,B10101001,B10000001,B00101011}, // -4.80db (1.737 times)
  {B01001000,B11010001,B10101100,B11010111}, // -4.90db (1.757 times)
  {B01000111,B11111100,B01010000,B11100011}, // -5.00db (1.778 times)
  {B01000111,B00101001,B01100110,B00010100}, // -5.10db (1.798 times)
  {B01000110,B01011000,B11100101,B01000001}, // -5.20db (1.819 times)
  {B01000101,B10001010,B11000111,B01011000}, // -5.30db (1.840 times)
  {B01000100,B10111111,B00000101,B01011010}, // -5.40db (1.861 times)
  {B01000011,B11110101,B10011000,B01011111}, // -5.50db (1.883 times)
  {B01000011,B00101110,B01111001,B10010000}, // -5.60db (1.905 times)
  {B01000010,B01101001,B10100010,B00101101}, // -5.70db (1.927 times)
  {B01000001,B10100111,B00001011,B10001001}, // -5.80db (1.949 times)
  {B01000000,B11100110,B10101111,B00001001}, // -5.90db (1.972 times)
  {B01000000,B00101000,B10000110,B00100111}, // -6.00db (1.995 times)
  {B00111111,B01101100,B10001010,B01110000}, // -6.10db (2.018 times)
  {B00111110,B10110010,B10110101,B10000010}, // -6.20db (2.041 times)
  {B00111101,B11111011,B00000001,B00010001}, // -6.30db (2.065 times)
  {B00111101,B01000101,B01100110,B11100001}, // -6.40db (2.089 times)
  {B00111100,B10010001,B11100000,B11001001}, // -6.50db (2.113 times)
  {B00111011,B11100000,B01101000,B10110010}, // -6.60db (2.137 times)
  {B00111011,B00110000,B11111000,B10010110}, // -6.70db (2.162 times)
  {B00111010,B10000011,B10001010,B10000010}, // -6.80db (2.187 times)
  {B00111001,B11011000,B00011000,B10010101}, // -6.90db (2.212 times)
  {B00111001,B00101110,B10011100,B11111100}, // -7.00db (2.238 times)
  {B00111000,B10000111,B00010001,B11111001}, // -7.10db (2.264 times)
  {B00110111,B11100001,B01110001,B11011100}, // -7.20db (2.290 times)
  {B00110111,B00111101,B10110111,B00000111}, // -7.30db (2.317 times)
  {B00110110,B10011011,B11011011,B11101100}, // -7.40db (2.343 times)
  {B00110101,B11111011,B11011011,B00001110}, // -7.50db (2.371 times)
  {B00110101,B01011101,B10101110,B11111110}, // -7.60db (2.398 times)
  {B00110100,B11000001,B01010010,B01100000}, // -7.70db (2.426 times)
  {B00110100,B00100110,B10111111,B11100110}, // -7.80db (2.454 times)
  {B00110011,B10001101,B11110010,B01010000}, // -7.90db (2.482 times)
  {B00110010,B11110110,B11100100,B01110001}, // -8.00db (2.511 times)
  {B00110010,B01100001,B10010001,B00101001}, // -8.10db (2.540 times)
  {B00110001,B11001101,B11110011,B01100101}, // -8.20db (2.570 times)
  {B00110001,B00111100,B00000110,B00100110}, // -8.30db (2.599 times)
  {B00110000,B10101011,B11000100,B01110111}, // -8.40db (2.629 times)
  {B00110000,B00011101,B00101001,B01110100}, // -8.50db (2.660 times)
  {B00101111,B10010000,B00110000,B01000110}, // -8.60db (2.691 times)
  {B00101111,B00000100,B11010100,B00100100}, // -8.70db (2.722 times)
  {B00101110,B01111011,B00010000,B01010110}, // -8.80db (2.753 times)
  {B00101101,B11110010,B11100000,B00101110}, // -8.90db (2.785 times)
  {B00101101,B01101100,B00111111,B00001110}, // -9.00db (2.817 times)
  {B00101100,B11100111,B00101000,B01100100}, // -9.10db (2.850 times)
  {B00101100,B01100011,B10010111,B10101101}, // -9.20db (2.883 times)
  {B00101011,B11100001,B10001000,B01110010}, // -9.30db (2.916 times)
  {B00101011,B01100000,B11110110,B01001010}, // -9.40db (2.950 times)
  {B00101010,B11100001,B11011100,B11011000}, // -9.50db (2.984 times)
  {B00101010,B01100100,B00110111,B11001101}, // -9.60db (3.019 times)
  {B00101001,B11101000,B00000010,B11100101}, // -9.70db (3.054 times)
  {B00101001,B01101101,B00111001,B11101001}, // -9.80db (3.089 times)
  {B00101000,B11110011,B11011000,B10110000}, // -9.90db (3.125 times)
  {B00101000,B01111011,B11011011,B00011011}, // -10.00db (3.161 times)
  {B00101000,B00000101,B00111101,B00011001}, // -10.10db (3.198 times)
  {B00100111,B10001111,B11111010,B10100010}, // -10.20db (3.235 times)
  {B00100111,B00011100,B00001111,B10111110}, // -10.30db (3.272 times)
  {B00100110,B10101001,B01111000,B01111100}, // -10.40db (3.310 times)
  {B00100110,B00111000,B00110000,B11111011}, // -10.50db (3.349 times)
  {B00100101,B11001000,B00110101,B01100010}, // -10.60db (3.387 times)
  {B00100101,B01011001,B10000001,B11100101}, // -10.70db (3.427 times)
  {B00100100,B11101100,B00010010,B11000010}, // -10.80db (3.466 times)
  {B00100100,B01111111,B11100100,B01000011}, // -10.90db (3.506 times)
  {B00100100,B00010100,B11110010,B10111101}, // -11.00db (3.547 times)
  {B00100011,B10101011,B00111010,B10001111}, // -11.10db (3.588 times)
  {B00100011,B01000010,B10111000,B00100011}, // -11.20db (3.630 times)
  {B00100010,B11011011,B01100111,B11101101}, // -11.30db (3.672 times)
  {B00100010,B01110101,B01000110,B01101100}, // -11.40db (3.714 times)
  {B00100010,B00010000,B01010000,B00101001}, // -11.50db (3.757 times)
  {B00100001,B10101100,B10000001,B10111000}, // -11.60db (3.801 times)
  {B00100001,B01001001,B11010111,B10110101}, // -11.70db (3.845 times)
  {B00100000,B11101000,B01001110,B11000111}, // -11.80db (3.889 times)
  {B00100000,B10000111,B11100011,B10100001}, // -11.90db (3.934 times)
  {B00100000,B00101000,B10010010,B11111100} // -12.00db (3.980 times)
};


long _s_interval = 1000;
long _s_previousMillis = 0;

byte _s_settings[10][27];  // Array to hold parameter values
bool _s_flags[10][27];  // Array to hold parameter flags

void s_setup() {
  Wire.begin();
  
  s_mute();
  
  
  // reset
#ifdef RESET
  for (int r = 0; r < 27; r++) {
    _s_settings[0][r] = _s_read(r);
    
    for (int i = 0; i < 10; i++) {
      EEPROM.write((i * 100) + r * 2, 0);
    }
  }
#endif RESET
  
  
  for (int r = 0; r < 27; r++) {
    _s_settings[0][r] = _s_read(r);
    
    for (int i = 1; i < 10; i++) {
      _s_flags[i][r] = (EEPROM.read((i * 100) + r * 2) > 0);
      _s_settings[i][r] = EEPROM.read((i * 100) + r * 2 + 1);
    }
  }
  
  _s_settings[0][13] = B11111111;
  _s_settings[0][19] = B00000000;
  _s_settings[0][8]  = B01111111;     // SPDIF only -127db (?)
  _s_settings[0][9]  = B00000000;     // long
  _s_settings[0][16] = B00000000;    // do not ramp volume
  
  _s_settings[0][14] = B00001101; // Default value for register 14. We use a variable for reg 14 because it controls
  _s_settings[0][15] = B10101010;
  _s_settings[0][17] = B00000100;
  _s_settings[0][18] = B00000001;
  _s_settings[0][25] = B10;  // 0= allow all settings

  _s_settings[0][10] = B11001111;  // 11001111 or 0xCF (Jitter on, etc, MUTE DACs);
  _s_settings[0][8] = B01101000;

  _s_settings[0][11] = B10000110;

  _s_settings[0][12] = B00100000; // notch

  _s_settings[0][20] = B11111111; // MT
  _s_settings[0][21] = B11111111; // MT
  _s_settings[0][22] = B11111111; // MT
  _s_settings[0][23] = B01111111; // MT
}

void s_mute() {
#ifdef DEBUG
  Serial.println(F("MUTE"));
#endif DEBUG

  byte reg10 = _s_read(10);

  byte was = bitRead(reg10, 0);
  bitSet(reg10, 0);              // Set bit zero for reg 10: Mute DACs

  if (was == 0) {
    _s_write(10, reg10);    // Mute DACs. Earliest we can mute the DACs to avoid full volume
  }
}

void s_unmute() {
#ifdef DEBUG
  Serial.println(F("UNMUTE"));
#endif DEBUG

  byte reg10 = _s_read(10);

  byte was = bitRead(reg10, 0);
  bitClear(reg10, 0);                 // Clear bit zero of reg 10: unmute DACs

  if (was == 1) {
    _s_write(10, reg10);         // Unmute DACs
  }
}

void s_relock()
{
#ifdef DEBUG
  Serial.println(F("RELOCK"));
#endif DEBUG

  s_mute();

  byte reg17 = _s_read(17);

  bitSet (reg17, 5);
  _s_write(17, reg17);
  delay(50);
  bitClear(reg17, 5);
  _s_write(17, reg17);

  s_unmute();
}

byte _s_read(byte regAddr) {
  
  byte value;

  Wire.beginTransmission(0x48); // Hard coded the Sabre device address
  Wire.write(regAddr);          // Queues the address of the register
  Wire.endTransmission();       // Sends the address of the register
  Wire.requestFrom(0x48, 1);    // Hard coded to device, request one byte from address
  // specified with Wire.write()/wire.endTransmission()
  if (Wire.available()) {         // Wire.available indicates if data is available
    value = Wire.read();         // Wire.read() reads the data on the wire



    return value;
  } else {



    return 0;                   // In no data in the wire, then return 0 to indicate error
  }
}

void _s_write(byte regAddr, byte regVal) {
#ifdef DEBUG
  Serial.print(F("  write #"));
  Serial.print(regAddr);
  Serial.print(F(" ?"));
  Serial.println(regVal);
#endif DEBUG


  Wire.beginTransmission(0x48); // Hard coded to the the DAC device address for stereo
  // or mono left. For stereo same as writeSabreReg()
  Wire.write(regAddr);          // Specifying the address of register
  Wire.write(regVal);           // Writing the value into the register
  Wire.endTransmission();
}

byte s_reg(byte reg)
{
  byte value; byte was_value = _s_settings[status_sr_idx][reg];

  if (_s_flags[status_sr_idx][reg] > 0) {
    value = _s_settings[status_sr_idx][reg];
    
#ifdef DEBUG
  Serial.print(F("  read #"));
  Serial.print(reg);
  Serial.print(F("  "));
  Serial.println(value);
#endif DEBUG
  } else if (status_sr_idx > 0) {
    value = _s_settings[0][reg];
  } else {  
    value = _s_read(reg);
  }  

  
  if (was_value != value) {
    _s_settings[status_sr_idx][reg] = value;
    _s_flags[status_sr_idx][reg] = true;
    
    if (status_sr_idx > 0) {
      EEPROM.write((status_sr_idx * 100) + reg * 2, 1);
      EEPROM.write((status_sr_idx * 100) + reg * 2 + 1, value);
    
      _s_write(reg, value);
    }
  }
    
  return value;
}

boolean s_put(byte reg, byte value)
{
#ifdef DEBUG
  Serial.print(F("  put #"));
  Serial.print(reg);
  Serial.print(F("  for "));
  Serial.print(status_sr_idx);
  Serial.print(F(" "));
  Serial.println(value, BIN);
#endif DEBUG
  
  if (status_sr_idx > 0) {
    byte was_value = _s_settings[status_sr_idx][reg];
    
    if (was_value != value) {
      _s_settings[status_sr_idx][reg] = value;
      _s_flags[status_sr_idx][reg] = true;
      
      EEPROM.write((status_sr_idx * 100) + reg * 2, 1);
      EEPROM.write((status_sr_idx * 100) + reg * 2 + 1, value);
      
      _s_write(reg, value);
      
      return true;
    }
    
  }
  return false;
}


// -----------------------------------

byte s_getDPLLFilterNumber()
{
  byte reg10 = s_reg(10);
  byte reg25 = s_reg(25);
  byte reg11 = s_reg(11);
  
  if (bitRead(reg10, 2) == 0) {
    return 5; // "off"
  }
  if (bitRead(reg25, 1) == 1) {
    return 0; // "best"
  } else {
    byte width = bitRead(reg11, 4) * 4 + bitRead(reg11, 3) * 2 + bitRead(reg11, 2);

    if (width <= 1) {
      return 1;
    } else if (width <= 3) {
      return 2;
    } else if (width <= 5) {
      return 3;
    } else {
      return 4;
    }
  }
}

byte s_getQuantizer()
{
  byte reg15 = s_reg(15);
  
  #ifdef DEBUG
  Serial.print(F("Check QT: "));
  Serial.println(reg15);
#endif DEBUG
  
  switch (reg15)
  {
    case B0:
      return 6;

    case B1010101:
      {
        return 7;
      }

    case B10101010:
      {
        return 8;
      }

    case B11111111:
      return 9;
    default:
      return 6;
  }
}

boolean s_setQuantizer(byte value)
{
  byte reg14 = s_reg(14);
  byte reg15 = s_reg(15);
  
#ifdef DEBUG
  Serial.print(F("Set QT: "));
  Serial.println(value);
#endif DEBUG

  boolean changed = false;

  switch (value)
  {
    case 6:
      bitSet(reg14, 3);     // True diff
      reg15 = B0;           // 6-bit quantizer
      changed |= s_setMastertrim(0);
      break;

    case 7:
      bitSet(reg14, 3);     // True diff
      reg15 = B1010101;     // 7-bit quantizer
      changed |= s_setMastertrim(0);
      break;

    case 8:
      bitSet(reg14, 3);     // True diff
      reg15 = B10101010;    // 8-bit quantizer
      changed |= s_setMastertrim(60); // -6db
      break;

    case 9:
      bitClear(reg14, 3);   // Pseudo diff
      reg15 = B11111111;    // 9-bit quantizer
      changed |= s_setMastertrim(60);   // -6db
      break;
  }
    
  changed |= s_put(14, reg14);
  changed |= s_put(15, reg15);
  
  if (changed) {
    s_relock();
  }
  
  return changed;
}


boolean s_setDPLLFilterNumber(byte value)
{
  byte reg10 = s_reg(10);
  byte reg25 = s_reg(25);
  byte reg11 = s_reg(11);
  
#ifdef DEBUG
  Serial.print(F("Set DPLL: "));
  Serial.println(value);
#endif DEBUG

  switch (value)
  {
    case 0:
      bitSet(reg25, 1);           // Reg 25: set bit 1 for "use best dpll"
      bitSet(reg10, 2); // for sure
      break;

    case 1:
      bitClear(reg25, 1);         // Reg 25: Clear bit 1 for "use all settings"
      bitSet(reg10, 2); // for sure

      bitClear(reg11, 4); // 001
      bitClear(reg11, 3);
      bitSet(reg11, 2);

      break;
    case 2:
      bitClear(reg25, 1);         // Reg 25: Clear bit 1 for "use all settings"
      bitSet(reg10, 2); // for sure

      bitClear(reg11, 4); // 011
      bitSet(reg11, 3);
      bitSet(reg11, 2);

      break;

    case 3:
      bitClear(reg25, 1);         // Reg 25: Clear bit 1 for "use all settings"
      bitSet(reg10, 2); // for sure

      bitSet(reg11, 4); // 101
      bitClear(reg11, 3);
      bitSet(reg11, 2);


      break;

    case 4:
      bitClear(reg25, 1);         // Reg 25: Clear bit 1 for "use all settings"
      bitSet(reg10, 2); // for sure

      bitSet(reg11, 4); // 111
      bitSet(reg11, 3);
      bitSet(reg11, 2);

      break;
    case 5: // off
      bitSet(reg25, 1);         // Reg 25: Clear bit 1 for "use all settings"
      bitClear(reg10, 2);        // Clear bit 2 of reg 10: jitter reduction bypass

      bitClear(reg11, 4); // 000
      bitClear(reg11, 3);
      bitClear(reg11, 2);

      break;
  }

  boolean changed = false;
  changed |= s_put(10, reg10); // Write JT state
#ifdef DEBUG
  Serial.print(F("  ?"));
  Serial.println(changed);
#endif DEBUG
  changed |= s_put(11, reg11); // Write DPLL
#ifdef DEBUG
  Serial.print(F("  ?"));
  Serial.println(changed);
#endif DEBUG
  changed |= s_put(25, reg25); // Write value into reg 25 for best dpll
#ifdef DEBUG
  Serial.print(F("  ?"));
  Serial.println(changed);
#endif DEBUG
  
  if (changed) {
    s_relock();
  }
  
  return changed;
}


boolean s_setIirFilter(byte value)
{
#ifdef DEBUG
  Serial.print(F("Set IIR: "));
  Serial.println(value);
#endif DEBUG

  byte reg14 = s_reg(14);

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
  return s_put(14, reg14);
}

boolean s_setFirFilter(byte value)
{
#ifdef DEBUG
  Serial.print(F("Set FIR: "));
  Serial.println(value);
#endif DEBUG

  byte reg14 = s_reg(14);
  byte reg17 = s_reg(17);
  byte reg25= s_reg(25);

  if (value == 2) {
    bitClear(reg17, 6);
    bitClear(reg14, 0);         // Clear bit 0 of reg 14 for slow fir
    bitClear(reg25, 0); //  DPLL 1x
  } else if (value == 1) {


    bitClear(reg17, 6);
    bitSet(reg14, 0);           // Set bit 0 of reg 14 for sharp fir
    bitClear(reg25, 0); //  DPLL 1x
  } else {
    bitSet(reg17, 6);
    bitSet(reg17, 5);
    //bitSet(reg14, 0);

    s_put(17, reg17);
    delay(50);
    bitClear(reg17, 5);

    bitSet(reg25, 0); //  DPLL 128x
  }
  
  boolean changed = false;
  changed |= s_put(14, reg14); // Write JT state
  changed |= s_put(17, reg17); // Write DPLL
  changed |= s_put(25, reg25); // Write value into reg 25 for best dpll
  
  return changed;
}

byte s_getIirFilter()
{
  byte reg14 = s_reg(14);
  
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

byte s_getFirFilter()
{
  byte reg17 = s_reg(17);
  
  if (bitRead(reg17, 6) == 1) {
    return 0;
  } else {
    byte reg14 = s_reg(14);
    
    if (bitRead(reg14, 0) == 1) {
      return 1;
    } else {
      return 2;
    }
  }
}


boolean s_setMastertrim(int decDb)
{

    decDb = constrain(decDb, 0, 120);

    byte reg23 = mastertrim[decDb][0];
    byte reg22 = mastertrim[decDb][1];
    byte reg21 = mastertrim[decDb][2];
    byte reg20 = mastertrim[decDb][3];

    boolean changed = false;
    changed |= s_put(23, reg23);
    changed |= s_put(22, reg22);
    changed |= s_put(21, reg21);
    changed |= s_put(20, reg20);
    
#ifdef DEBUG
  Serial.println(F("MT"));
  Serial.print(F("db: ")); Serial.println(decDb, DEC);
  Serial.print(F("23: ")); Serial.println(reg23, DEC);
  Serial.print(F("22: ")); Serial.println(reg22, DEC);
  Serial.print(F("21: ")); Serial.println(reg21, DEC);
  Serial.print(F("20: ")); Serial.println(reg20, DEC);
  Serial.println(F("---"));
#endif DEBUG

    return changed;
}

// -----------------------------------

void s_loop() {

  boolean was_status_isdsd = status_isdsd;
  boolean was_status_islock = status_islock;
  byte was_status_sr_idx = status_sr_idx;

  

  if (!status_islock) {
    byte chipStatus = _s_read(27);

    if (chipStatus & B00000001) {
      status_islock = true;
      status_sr = _s_sample_rate();
      status_sr_idx = _s_sample_rate_idx();
      status_isdsd = (chipStatus & B00001000);
    } else {
      status_islock = false;
    }
  } else {
    unsigned long currentMillis = millis();
    
    if (currentMillis - _s_previousMillis > _s_interval) {
      // save the last time you blinked the LED
      _s_previousMillis = currentMillis;
  
      byte chipStatus = _s_read(27);
  
      if (chipStatus & B00000001) {
        status_islock = true;
        status_sr = _s_sample_rate();
        status_sr_idx = _s_sample_rate_idx();
        status_isdsd = (chipStatus & B00001000);
  
      } else {
        status_islock = false;
      }
    }
  }
  
  if ((was_status_isdsd != status_isdsd) || (was_status_islock != status_islock) || (was_status_sr_idx != status_sr_idx)) {
    s_changed();
  }
}

void s_changed() {
#ifdef DEBUG
  Serial.println(F("SABRE CHANGED"));
  Serial.print(F("dsd: ")); Serial.println(status_isdsd, BIN);
  Serial.print(F("lock: ")); Serial.println(status_islock, BIN);
  Serial.print(F("idx: ")); Serial.println(status_sr_idx, DEC);
  Serial.print(F("F: ")); Serial.println(status_sr, DEC);
  Serial.println(F("---"));
#endif DEBUG


  if (status_sr_idx > 0 && status_islock) {
    for (int r = 0; r < 27; r++) {
      s_put(r, s_reg(r));
    }
    
    s_unmute();
  } else {
    s_mute();
  }


  dpll = s_getDPLLFilterNumber();

  //s_setDPLLFilterNumber(dpll);

  qt = s_getQuantizer();
  s_setQuantizer(qt); //  to reinit all

  if (status_isdsd) {
     filter = s_getIirFilter();
     //s_setIirFilter(filter);
  } else {
     filter = s_getFirFilter();
     //s_setFirFilter(filter);
  }
}

byte _s_sample_rate_idx() {
  

  if (status_islock) {
    if (status_isdsd) {
      return 10;
    } else {
      if (status_sr <= 45000) {
        // 44
        return 1;
      } else if (status_sr <= 89000) {
        // 88
        return 2;
      } else if (status_sr <= 99000) {
        // 96
        return 3;
      } else if (status_sr <= 177000) {
        // 176
        return 6;
      } else if (status_sr <= 193000) {
        // 192
        return 7;
      } else if (status_sr <= 355000) {
        // 352.8
        return 8;
      } else if (status_sr <= 385000) {
        // 384
        return 9;
      } else { // ?
        return 0;
      }
    }
  } else {
    return 0;
  }
}

unsigned long _s_sample_rate() {


  unsigned long DPLLNum = 0;

  // Reading the 4 registers of DPLL one byte at a time and stuffing into a single 32-bit number
  DPLLNum |= _s_read(31);
  DPLLNum <<= 8;
  DPLLNum |= _s_read(30);
  DPLLNum <<= 8;
  DPLLNum |= _s_read(29);
  DPLLNum <<= 8;
  DPLLNum |= _s_read(28);

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

  byte reg_17 = _s_read(17);
  if (bitRead(reg_17, 6) == 1) { // When OSF is bypassed, the magnitude of DPLL is reduced by a factor of 64
    DPLLNum *= 64;
  }

  return DPLLNum;
}

