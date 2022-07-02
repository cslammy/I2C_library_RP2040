/*
 * mcp4728-test.c
 * https://www.microchip.com/wwwproducts/en/MCP4728
  
 6-19-22 port from Atmel 328 to rp2040
 
 */ 


#include <stdint.h>
 
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "I2C_rp2040.h"
 #include <stdio.h>


void Fast4728(uint16_t chA, uint16_t chB, uint16_t chC, uint16_t chD, uint8_t *aa)
{
	uint16_t rety = 0; 
	printf("In Fast4728! \n");
    uint16_t data[4]; // array to hold values for "multi channel write"	

	///address of MCP4728   
	const uint addr = 0x60;
	 
	 		 
	 //write these values to memory
	 data[0] = chA;
	 data[1] = chB;
	 data[2] = chC;
	 data[3] = chD;
	 
	  
	
	 
     for (uint8_t x = 0; x < 4; x++) 
	 {    
	    uint8_t g = 0;
		g = x*2;
	 uint8_t MSB = (data[x] >> 8) ;
         
 
		  if (data[x] > 4096) // we don't want a value above 1<<12 to screw up write!
	 	 {
		 	 MSB = 0x0F;
	 	 }	 
	 
    
	 
	 //isolate LSB AND WRITE
	 uint8_t LSB = data[x] & 0x00FF;
	 aa[g]=MSB;
	 aa[g+1]=LSB;
	 printf("aa%d is: %x \n",g,aa[g]);
     printf("aa%d is: %x \n",g+1,aa[g+1]);
	
    printf ("MCP4728 received %d bytes on pass %d \n", rety,x);

	 }
 
    rety = I2C_Write_nbytes_stop(i2c0,addr, aa, 8); 
    printf("MCP4728 fast write--wrote %d bytes \n",rety);
 
    
	
      
}


           
       
        

