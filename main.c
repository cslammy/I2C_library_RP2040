#include "pico/stdlib.h"
#include <stdint.h>
#include <stdio.h>
#include "mcp4728.h"
#include "I2C_rp2040.h"
#include "pcf8591.h"



int main() {
 stdio_init_all();




// initialize i2c0 
 I2C_Init0(100000);

 I2C_Pins(4,5);
 
uint8_t buff[8]; // buffer to hold MSB and LSB for MCP4728--"fast write" I2C call is addr + 8 bytes
uint8_t ibuff[1]; //buffer to hold return data from PCF8591

//loop dukie here
    while (2 > 0) {
    for (uint8_t tmr = 0; tmr < 200; tmr++)
        {
        sleep_ms(100);
        
        //test write 4 chans I2C to MCP4728 quad dac by uncommenting next 2 lines....
        //printf("%d sending 4 chan to MCP4728-------------------------- \n",tmr);
        //Fast4728(1000,2000,3000,4000,buff);
        
        //test read from PCF8591 quad 8 bit ADC

        read_pcf8591_data (3,ibuff);
        sleep_ms(100);
      
        printf("data read from PFC8591 is: %d \n",ibuff[0]);
        }
    } 
return 0;
}