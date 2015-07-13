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
#endif DEBUG
  
  
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
  _s_settings[0][23] = B00111111; // MT
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

  switch (value)
  {
    case 6:
      bitSet(reg14, 3);     // True diff
      reg15 = B0;           // 6-bit quantizer
      //dac_mastertrim(0);
      break;

    case 7:
      bitSet(reg14, 3);     // True diff
      reg15 = B1010101;     // 7-bit quantizer
      //dac_mastertrim(0);
      break;

    case 8:
      bitSet(reg14, 3);     // True diff
      reg15 = B10101010;    // 8-bit quantizer
      //dac_mastertrim(6);
      break;

    case 9:
      bitClear(reg14, 3);   // Pseudo diff
      reg15 = B11111111;    // 9-bit quantizer
      //dac_mastertrim(6);
      break;
  }
    
  boolean changed = false;
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
  qt = s_getQuantizer();
  filter = status_isdsd ? s_getIirFilter() : s_getFirFilter();
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

