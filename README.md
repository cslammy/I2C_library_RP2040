# I2C_library_RP2040
I2C library for RP2040 MCU
Wrote this for quick I2C coding using RP2040 and its C SDK.  Also include example calls in main.c and a few functions for 2 popular I2C IC's--PCF8591 (quad 8 bit ADC)and MCP4728 (quad 12 bit DAC.  

For information please see the blog post: http://audiodiwhy.blogspot.com/2022/07/rp2040-i2c-library-for-embedded-c.html

Note--I wrote this library to make sure I understand the basics of the I2C tools found in the Pico RP2040 SDK. And to make I2C calls work more like the way my mind works vs. the minds of the folks at Rpi. You may or may not want to include some of these files in your own code; in some use cases it may make more sense to incorporate the RP2040 SDK function calls directly into your code rather than use this library. 

However, I use this library in some of my own C projects, so you will see it elsewhere in this repo.
