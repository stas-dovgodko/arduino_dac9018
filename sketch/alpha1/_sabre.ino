
// Master trims tables

byte mtrim[120][4];
mtrim[0] = {B11111111, B11111111, B11111111, B11111111}; // -0.00db (1.000 times)
mtrim[1] = {B11111010, B00100110, B11000001, B00100000}; // -0.10db (1.023 times)
mtrim[2] = {B11110100, B01101111, B10110111, B00010010}; // -0.20db (1.047 times)
mtrim[3] = {B11101110, B11011010, B00011001, B11000101}; // -0.30db (1.071 times)
mtrim[4] = {B11101001, B01100101, B00100101, B10111100}; // -0.40db (1.096 times)
mtrim[5] = {B11100100, B00010000, B00011011, B11110001}; // -0.50db (1.122 times)
mtrim[6] = {B11011110, B11011010, B01000001, B10111011}; // -0.60db (1.148 times)
mtrim[7] = {B11011001, B11000010, B11100000, B10110111}; // -0.70db (1.175 times)
mtrim[8] = {B11010100, B11001001, B01000110, B10101000}; // -0.80db (1.203 times)
mtrim[9] = {B11001111, B11101100, B11000101, B01101000}; // -0.90db (1.231 times)
mtrim[10] = {B11001011, B00101100, B10110010, B11001010}; // -1.00db (1.260 times)
mtrim[11] = {B11000110, B10001000, B01101000, B10000011}; // -1.10db (1.289 times)
mtrim[12] = {B11000001, B11111111, B01000100, B00010110}; // -1.20db (1.319 times)
mtrim[13] = {B10111101, B10010000, B10100110, B10111101}; // -1.30db (1.350 times)
mtrim[14] = {B10111001, B00111011, B11110101, B01010000}; // -1.40db (1.382 times)
mtrim[15] = {B10110101, B00000000, B10011000, B00110101}; // -1.50db (1.414 times)
mtrim[16] = {B10110000, B11011101, B11111011, B01000111}; // -1.60db (1.447 times)
mtrim[17] = {B10101100, B11010011, B10001101, B11000110}; // -1.70db (1.481 times)
mtrim[18] = {B10101000, B11100000, B11000010, B00111100}; // -1.80db (1.515 times)
mtrim[19] = {B10100101, B00000101, B00001110, B01110011}; // -1.90db (1.551 times)
mtrim[20] = {B10100001, B00111111, B11101011, B01011011}; // -2.00db (1.587 times)
mtrim[21] = {B10011101, B10010000, B11010100, B11111010}; // -2.10db (1.624 times)
mtrim[22] = {B10011001, B11110111, B01001010, B01011011}; // -2.20db (1.662 times)
mtrim[23] = {B10010110, B01110010, B11001101, B01111001}; // -2.30db (1.701 times)
mtrim[24] = {B10010011, B00000010, B11100011, B00110011}; // -2.40db (1.741 times)
mtrim[25] = {B10001111, B10100111, B00010011, B00110110}; // -2.50db (1.782 times)
mtrim[26] = {B10001100, B01011110, B11100111, B11101111}; // -2.60db (1.823 times)
mtrim[27] = {B10001001, B00101001, B11101110, B01111100}; // -2.70db (1.866 times)
mtrim[28] = {B10000110, B00000111, B10110110, B10011001}; // -2.80db (1.910 times)
mtrim[29] = {B10000010, B11110111, B11010010, B10010100}; // -2.90db (1.954 times)
mtrim[30] = {B01111111, B11111001, B11010111, B00111100}; // -3.00db (2.000 times)
mtrim[31] = {B01111101, B00001101, B01011011, B11010011}; // -3.10db (2.047 times)
mtrim[32] = {B01111010, B00110001, B11111001, B11111111}; // -3.20db (2.095 times)
mtrim[33] = {B01110111, B01100111, B01001101, B10111110}; // -3.30db (2.143 times)
mtrim[34] = {B01110100, B10101100, B11110101, B01010101}; // -3.40db (2.194 times)
mtrim[35] = {B01110010, B00000010, B10010001, B01000111}; // -3.50db (2.245 times)
mtrim[36] = {B01101111, B01100111, B11000100, B01000100}; // -3.60db (2.297 times)
mtrim[37] = {B01101100, B11011100, B00110011, B00011101}; // -3.70db (2.351 times)
mtrim[38] = {B01101010, B01011111, B10000100, B10111011}; // -3.80db (2.406 times)
mtrim[39] = {B01100111, B11110001, B01100010, B00001100}; // -3.90db (2.462 times)
mtrim[40] = {B01100101, B10010001, B01110101, B11111111}; // -4.00db (2.520 times)
mtrim[41] = {B01100011, B00111111, B01101101, B01110010}; // -4.10db (2.579 times)
mtrim[42] = {B01100000, B11111010, B11110111, B00101100}; // -4.20db (2.639 times)
mtrim[43] = {B01011110, B11000011, B11000011, B11001011}; // -4.30db (2.701 times)
mtrim[44] = {B01011100, B10011001, B10000101, B11000001}; // -4.40db (2.764 times)
mtrim[45] = {B01011010, B01111011, B11110001, B01000101}; // -4.50db (2.829 times)
mtrim[46] = {B01011000, B01101010, B10111100, B01000110}; // -4.60db (2.895 times)
mtrim[47] = {B01010110, B01100101, B10011110, B01101001}; // -4.70db (2.963 times)
mtrim[48] = {B01010100, B01101100, B01010000, B11110110}; // -4.80db (3.032 times)
mtrim[49] = {B01010010, B01111110, B10001110, B11010100}; // -4.90db (3.103 times)
mtrim[50] = {B01010000, B10011100, B00010100, B10000001}; // -5.00db (3.175 times)
mtrim[51] = {B01001110, B11000100, B10100000, B00000001}; // -5.10db (3.250 times)
mtrim[52] = {B01001100, B11110111, B11110000, B11011101}; // -5.20db (3.326 times)
mtrim[53] = {B01001011, B00110101, B11001000, B00010111}; // -5.30db (3.403 times)
mtrim[54] = {B01001001, B01111101, B11101000, B00100000}; // -5.40db (3.483 times)
mtrim[55] = {B01000111, B11010000, B00010100, B11010001}; // -5.50db (3.564 times)
mtrim[56] = {B01000110, B00101100, B00010011, B01100100}; // -5.60db (3.648 times)
mtrim[57] = {B01000100, B10010001, B10101010, B01101011}; // -5.70db (3.733 times)
mtrim[58] = {B01000011, B00000000, B10100001, B11000111}; // -5.80db (3.820 times)
mtrim[59] = {B01000001, B01111000, B11000010, B10100000}; // -5.90db (3.910 times)
mtrim[60] = {B00111111, B11111001, B11010111, B01100010}; // -6.00db (4.001 times)
mtrim[61] = {B00111110, B10000011, B10101011, B10110000}; // -6.10db (4.095 times)
mtrim[62] = {B00111101, B00010110, B00001100, B01011110}; // -6.20db (4.190 times)
mtrim[63] = {B00111011, B10110000, B11000111, B01110000}; // -6.30db (4.288 times)
mtrim[64] = {B00111010, B01010011, B10101100, B00001001}; // -6.40db (4.389 times)
mtrim[65] = {B00111000, B11111110, B10001010, B01101101}; // -6.50db (4.491 times)
mtrim[66] = {B00110111, B10110001, B00110011, B11110110}; // -6.60db (4.596 times)
mtrim[67] = {B00110110, B01101011, B01111011, B00010000}; // -6.70db (4.704 times)
mtrim[68] = {B00110101, B00101101, B00110011, B00110000}; // -6.80db (4.814 times)
mtrim[69] = {B00110011, B11110110, B00110000, B11010000}; // -6.90db (4.926 times)
mtrim[70] = {B00110010, B11000110, B01001001, B01101010}; // -7.00db (5.041 times)
mtrim[71] = {B00110001, B10011101, B01010011, B01101111}; // -7.10db (5.159 times)
mtrim[72] = {B00110000, B01111011, B00100110, B01000011}; // -7.20db (5.280 times)
mtrim[73] = {B00101111, B01011111, B10011010, B00111000}; // -7.30db (5.403 times)
mtrim[74] = {B00101110, B01001010, B10001000, B10001001}; // -7.40db (5.530 times)
mtrim[75] = {B00101101, B00111011, B11001011, B01010010}; // -7.50db (5.659 times)
mtrim[76] = {B00101100, B00110011, B00111101, B10001110}; // -7.60db (5.791 times)
mtrim[77] = {B00101011, B00110000, B10111011, B00010001}; // -7.70db (5.927 times)
mtrim[78] = {B00101010, B00110100, B00100000, B01111111}; // -7.80db (6.065 times)
mtrim[79] = {B00101001, B00111101, B01001011, B01010000}; // -7.90db (6.207 times)
mtrim[80] = {B00101000, B01001100, B00011001, B11000010}; // -8.00db (6.352 times)
mtrim[81] = {B00100111, B01100000, B01101010, B11011010}; // -8.10db (6.501 times)
mtrim[82] = {B00100110, B01111010, B00011110, B01011101}; // -8.20db (6.653 times)
mtrim[83] = {B00100101, B10011001, B00010100, B11001111}; // -8.30db (6.808 times)
mtrim[84] = {B00100100, B10111101, B00101111, B01101000}; // -8.40db (6.968 times)
mtrim[85] = {B00100011, B11100110, B01010000, B00011000}; // -8.50db (7.130 times)
mtrim[86] = {B00100011, B00010100, B01011001, B01111101}; // -8.60db (7.297 times)
mtrim[87] = {B00100010, B01000111, B00101110, B11100000}; // -8.70db (7.468 times)
mtrim[88] = {B00100001, B01111110, B10110100, B00110100}; // -8.80db (7.642 times)
mtrim[89] = {B00100000, B10111010, B11001110, B00001111}; // -8.90db (7.821 times)
mtrim[90] = {B00011111, B11111011, B01100001, B10100110}; // -9.00db (8.004 times)
mtrim[91] = {B00011111, B01000000, B01010100, B11001101}; // -9.10db (8.191 times)
mtrim[92] = {B00011110, B10001001, B10001101, B11110001}; // -9.20db (8.383 times)
mtrim[93] = {B00011101, B11010110, B11110100, B00010010}; // -9.30db (8.579 times)
mtrim[94] = {B00011101, B00101000, B01101110, B11000101}; // -9.40db (8.779 times)
mtrim[95] = {B00011100, B01111101, B11100110, B00101100}; // -9.50db (8.985 times)
mtrim[96] = {B00011011, B11010111, B01000010, B11110101}; // -9.60db (9.195 times)
mtrim[97] = {B00011011, B00110100, B01101110, B01011001}; // -9.70db (9.410 times)
mtrim[98] = {B00011010, B10010101, B01010010, B00010001}; // -9.80db (9.630 times)
mtrim[99] = {B00011001, B11111001, B11011000, B01011101}; // -9.90db (9.855 times)
mtrim[100] = {B00011001, B01100001, B11101011, B11111001}; // -10.00db (10.085 times)
mtrim[101] = {B00011000, B11001101, B01111000, B00100001}; // -10.10db (10.321 times)
mtrim[102] = {B00011000, B00111100, B01101000, B10000110}; // -10.20db (10.562 times)
mtrim[103] = {B00010111, B10101110, B10101001, B01010011}; // -10.30db (10.809 times)
mtrim[104] = {B00010111, B00100100, B00100111, B00100110}; // -10.40db (11.062 times)
mtrim[105] = {B00010110, B10011100, B11001111, B00001110}; // -10.50db (11.321 times)
mtrim[106] = {B00010110, B00011000, B10001110, B10001010}; // -10.60db (11.585 times)
mtrim[107] = {B00010101, B10010111, B01010011, B10000011}; // -10.70db (11.856 times)
mtrim[108] = {B00010101, B00011001, B00001100, B01001110}; // -10.80db (12.133 times)
mtrim[109] = {B00010100, B10011101, B10100111, B10100111}; // -10.90db (12.417 times)
mtrim[110] = {B00010100, B00100101, B00010100, B10101110}; // -11.00db (12.707 times)
mtrim[111] = {B00010011, B10101111, B01000010, B11100101}; // -11.10db (13.005 times)
mtrim[112] = {B00010011, B00111100, B00100010, B00110001}; // -11.20db (13.309 times)
mtrim[113] = {B00010010, B11001011, B10100010, B11010100}; // -11.30db (13.620 times)
mtrim[114] = {B00010010, B01011101, B10110101, B01101011}; // -11.40db (13.938 times)
mtrim[115] = {B00010001, B11110010, B01001010, B11101111}; // -11.50db (14.264 times)
mtrim[116] = {B00010001, B10001001, B01010100, B10101110}; // -11.60db (14.598 times)
mtrim[117] = {B00010001, B00100010, B11000100, B01010000}; // -11.70db (14.939 times)
mtrim[118] = {B00010000, B10111110, B10001011, B11001100}; // -11.80db (15.288 times)
mtrim[119] = {B00010000, B01011100, B10011101, B01110000}; // -11.90db (15.646 times)
mtrim[120] = {B00001111, B11111100, B11101011, B11010111}; // -12.00db (16.012 times)

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
  _s_settings[0][23] = B11111111; // MT
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

    byte reg23 = mtrim[decDb][0];
    byte reg22 = mtrim[decDb][1];
    byte reg21 = mtrim[decDb][2];
    byte reg20 = mtrim[decDb][3];

    boolean changed = false;
    changed |= s_put(23, reg23);
    changed |= s_put(22, reg22);
    changed |= s_put(21, reg21);
    changed |= s_put(20, reg20);

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

  s_setDPLLFilterNumber(dpll);

  qt = s_getQuantizer();
  s_setQuantizer(qt); //  to reinit all

  if (status_isdsd) {
     filter = s_getIirFilter();
     s_setIirFilter(filter);
  } else {
     filter = s_getFirFilter();
     s_setFirFilter(filter);
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

