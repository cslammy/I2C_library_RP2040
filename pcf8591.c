#include "pcf8591.h"
#include "pico/stdlib.h"
#include <stdint.h>
#include <stdio.h>
#include "I2C_rp2040.h"

uint8_t control_byte = 0b01000000; // 4 ADCs, no auto incr
uint8_t rety = 0; //return data from ADC write--how many bytes written?
uint8_t aa[1] = {0}; //buffer
uint8_t data_from_adc[1] = {0};
uint8_t ibuff2[1] = {0};
const uint addr = 0x48;

//read a byte from channel of PCF8591
//channel 0,1,2 or 3.
uint8_t read_pcf8591_data (uint8_t channel, uint8_t *ibuff)
{ 

if (channel > 3)
{
    channel = 0;
}



aa[0] = control_byte + channel;
//BOB from tayda el cheapo PCF8591 is hard wired to addr 0x90 for write and 0x91 for read--sorry
//write control data to IC
rety = I2C_Write_nbytes_stop(i2c0,addr, aa, 1); 
//printf("aa value is: %d and hex is 0x%x \n",aa[0], aa[0]);

if (rety > 0)
{
printf("wrote byte to PCF8591 \n");
}
else
{
printf("did not write byte to IC \n");
}

//read data. Result goes into ibuff array--I see docs that say to read a throwaway byte first, not sure it's needed, but what is below seems to work.
I2C_Read_nbytes_stop(i2c0,addr, ibuff2, 1); 
I2C_Read_nbytes_stop(i2c0,addr, ibuff, 1); 
}


