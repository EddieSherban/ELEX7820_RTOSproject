
/*
*
* by Lewis Loflin www.bristolwatch.com lewis@bvu.net
* http://www.bristolwatch.com/rpi/i2clcd.htm
* Using wiringPi by Gordon Henderson
*
*
* Port over lcd_i2c.py to C and added improvements.
* Supports 16x2 and 20x4 screens.
* This was to learn now the I2C lcd displays operate.
* There is no warrenty of any kind use at your own risk.
*
*/

// Modified by Felix Serban 2023-12-05. Search "FS".

#include "WiringPi/wiringPi/wiringPi.h"
#include "WiringPi/wiringPi/wiringPiI2C.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>

// Define some device parameters
#define I2C_ADDR   0x27 // I2C device address

// Define some device constants
#define LCD_CHR  1 // Mode - Sending data
#define LCD_CMD  0 // Mode - Sending command

#define LINE1  0x80 // 1st line
#define LINE2  0xC0 // 2nd line
#define LINE3  0x94 // FS
#define LINE4  0xD4 // FS

#define LCD_BACKLIGHT   0x08  // On
//#define LCD_BACKLIGHT   0x00  // Off

#define ENABLE  0b00000100 // Enable bit

void lcd_init(void);
void lcd_byte(int bits, int mode);
void lcd_toggle_enable(int bits);

// added by Lewis
void typeInt(int i);
void typeIntPad3(int i);
void typeIntPad5(int i);
void typeFloat(float myFloat);
void lcdLoc(int line); //move cursor
void ClrLcd(void); // clr LCD return home
void typeln(const char *s);
void typeChar(char val);
void typeString(std::string full);
int fd;  // seen by all subroutines

extern int  _state,
            _ballX,
            _ballY,
            _car1,
            _car2,
            _score1,
            _score2;

//
void do_lcd()
{
    if (wiringPiSetup () == -1)
        exit (1);

    fd = wiringPiI2CSetup(I2C_ADDR);

    lcd_init(); // setup LCD
    ClrLcd();

    while (true)
    {
        lcdLoc(LINE1);
        typeln("Ball>X:");
        lcdLoc(LINE1 + 7);
        typeln("12345");
        lcdLoc(LINE1 + 12);
        typeln(",Y:");
        lcdLoc(LINE1 + 15);
        typeln("12345");

        lcdLoc(LINE2);
        typeln("Cars>A:");
        lcdLoc(LINE2 + 7);
        typeln("12345");
        lcdLoc(LINE2 + 12);
        typeln(",B:");
        lcdLoc(LINE2 + 15);
        typeln("12345");

        lcdLoc(LINE3);
        typeln("<S");
        lcdLoc(LINE3 + 2);
        typeIntPad3(_state);
        lcdLoc(LINE3 + 5);
        typeln(">");
        lcdLoc(LINE3 + 6);
        typeln(" P1:");
        lcdLoc(LINE3 + 10);
        typeIntPad3(_score1);
        lcdLoc(LINE3 + 13);
        typeln(" P2:");
        lcdLoc(LINE3 + 17);
        typeIntPad3(_score2);

        lcdLoc(LINE4);
        typeln("State description...");
    }
}

int lcd_test()   {

  if (wiringPiSetup () == -1) exit (1);

  fd = wiringPiI2CSetup(I2C_ADDR);

  //printf("fd = %d ", fd);

  lcd_init(); // setup LCD

  char array1[] = "Hello world!";

  char array2[] =       "DsuncsUHhwE3OmJJ77cB90OgWbxteeNrZDBkZUqU7oZo15lQkWLLEGibWjhK16Qm5tJngpQYuoM3qYdL";
  char array3[] =       "Here is an example of a long string of text. I wonder if it will work properly~~";
  std::string test =    "This is a string of eighty characters that happens to be the exact number I need";

  while (1)   {

    ClrLcd();
    lcdLoc(LINE1);
    typeln("Using wiringPi");
    lcdLoc(LINE2);
    typeln("Geany editor.");

    delay(2000);
    ClrLcd();
    lcdLoc(LINE1);
    typeln("I2c  Programmed");
    lcdLoc(LINE2);
    typeln("in C not Python.");

    delay(2000);
    ClrLcd();
    lcdLoc(LINE1);
    typeln("Arduino like");
    lcdLoc(LINE2);
    typeln("fast and easy.");
    lcdLoc(LINE3);
    typeln("Line 3 test.");

    delay(2000);
    ClrLcd();
    lcdLoc(LINE1);
    typeln(array1);

    delay(2000);
    ClrLcd();
    lcdLoc(LINE1);
    typeln(array3);
    delay(8000);

    delay(2000);
    ClrLcd();
    lcdLoc(LINE1);
    typeString(test);
    delay(8000);

    delay(2000);
    ClrLcd(); // defaults LINE1
    typeln("Int  ");
    int value = 20125;
    typeInt(value);

    delay(2000);
    lcdLoc(LINE2);
    typeln("Float ");
    float FloatVal = 10045.25989;
    typeFloat(FloatVal);
    delay(2000);
  }

  return 0;

}


// float to string
void typeFloat(float myFloat)   {
  char buffer[20];
  sprintf(buffer, "%4.2f",  myFloat);
  typeln(buffer);
}

// int to string
void typeInt(int i)   {
  char array1[20];
  sprintf(array1, "%d",  i);
  typeln(array1);
}

// int to string
void typeIntPad3(int i)   {
  char array1[20];
  sprintf(array1, "%03d",  i);
  typeln(array1);
}

// int to string
void typeIntPad5(int i)   {
  char array1[20];
  sprintf(array1, "%05d",  i);
  typeln(array1);
}

// clr lcd go home loc 0x80
void ClrLcd(void)   {
  lcd_byte(0x01, LCD_CMD);
  lcd_byte(0x02, LCD_CMD);
}

// go to location on LCD
void lcdLoc(int line)   {
  lcd_byte(line, LCD_CMD);
}

// out char to LCD at current position
void typeChar(char val)   {

  lcd_byte(val, LCD_CHR);
}

void typeString(std::string full)
{
    // Display has four lines, 20 characters each. 80 characters total.
    // Random string of text 80 characters long needed for some reason. char combinedChar[80] produces weird artifacts and overwrites three characters.
    char combinedChar[] = "DsuncsUHhwE3OmJJ77cB90OgWbxteeNrZDBkZUqU7oZo15lQkWLLEGibWjhK16Qm5tJngpQYuoM3qYdL";

    for (int i = 0; i < 20; i++)
    {
        combinedChar[i + 0] = full.substr(0,20)[i];
        combinedChar[i + 20] = full.substr(40,20)[i];
        combinedChar[i + 40] = full.substr(20,20)[i];
        combinedChar[i + 60] = full.substr(60,20)[i];
    }

    typeln(combinedChar);
}


// this allows use of any size string
void typeln(const char *s)   {

  while ( *s ) lcd_byte(*(s++), LCD_CHR);

}

void lcd_byte(int bits, int mode)   {

  //Send byte to data pins
  // bits = the data
  // mode = 1 for data, 0 for command
  int bits_high;
  int bits_low;
  // uses the two half byte writes to LCD
  bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT ;
  bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT ;


  // High bits
  wiringPiI2CReadReg8(fd, bits_high);
  lcd_toggle_enable(bits_high);

  // Low bits
  wiringPiI2CReadReg8(fd, bits_low);
  lcd_toggle_enable(bits_low);
}

void lcd_toggle_enable(int bits)   {
  // Toggle enable pin on LCD display
  delayMicroseconds(500);
  wiringPiI2CReadReg8(fd, (bits | ENABLE));
  delayMicroseconds(500);
  wiringPiI2CReadReg8(fd, (bits & ~ENABLE));
  delayMicroseconds(500);
}

void lcd_init()   {
  // Initialise display
  lcd_byte(0x33, LCD_CMD); // Initialise
  lcd_byte(0x32, LCD_CMD); // Initialise
  lcd_byte(0x06, LCD_CMD); // Cursor move direction
  lcd_byte(0x0C, LCD_CMD); // 0x0F On, Blink Off
  lcd_byte(0x28, LCD_CMD); // Data length, number of lines, font size
  lcd_byte(0x01, LCD_CMD); // Clear display
  delayMicroseconds(500);
}