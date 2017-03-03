/*
  LCD1x9.cpp - Library for using the Olimex 1x9 LCD UEXT module
  Created by Svetlozar Argirov, based on Olimex Sources
  Released into the public domain.
*/

#include <Arduino.h>
#include <Wire.h>

typedef  unsigned char BYTE;
typedef unsigned int WORD;
#include "LCD1x9.h"
#include "LCD1x9_mapping.h"

unsigned char LCD1x9::lcdBitmap[20];

#define LCD1x9_SLAVE_ADDR 0b00111000

void LCD1x9::initialize() {
  initialize(LCD1x9_SLAVE_ADDR);
}

void LCD1x9::initialize(int address)
{

  Wire.beginTransmission(address);
	Wire.write(0b11001000); // mode register
	Wire.write(0b11110000); // blink register
	Wire.write(0b11100000); // device select register
	Wire.write(0b00000000); // pointer register
	
	// light up all the segments, initialize the local display buffer as well
	for(int i = 0; i < 20; i++)
	{
		Wire.write(0xFF);
		lcdBitmap[i] = 0xFF;
	}	
	
	Wire.endTransmission();
}


void LCD1x9::enableSegment(BYTE comIndex, BYTE bitIndex)
{
	if(bitIndex >= 40)
		return;
		
	comIndex &= 0x3;
	
	if(bitIndex & 0x1)
		comIndex |= 0x4;
		
	bitIndex >>= 1;
	
	lcdBitmap[bitIndex] |= 0x80 >> comIndex;
}

void LCD1x9::disableSegment(BYTE comIndex, BYTE bitIndex)
{
	if(bitIndex >= 40)
		return;
		
	comIndex &= 0x3;
	
	if(bitIndex & 0x1)
		comIndex |= 0x4;
		
	bitIndex >>= 1;
	
	lcdBitmap[bitIndex] &= ~(0x80 >> comIndex);
}

void LCD1x9::update(void)
{
	BYTE i;
	
  Wire.beginTransmission(LCD1x9_SLAVE_ADDR | 0x00);
	Wire.write(0b11100000); // device select register
	Wire.write(0b00000000); // pointer register
	
	// send the local buffer to the device
	for(i = 0; i < 20; i++)
		Wire.write(lcdBitmap[i]);
		
	Wire.endTransmission();
}

void LCD1x9::write(char *string)
{
	BYTE data, length, index, i;
	WORD bitfield;
	BYTE com, bit;
	
	length = strlen(string);
	
	index  = 0;
	/* fill out all characters on display */
	for (index = 0; index < 9; index++)
	{
		if (index < length)
		{
			data = (BYTE)string[index];
		}
		else
		{
			data = 0x20; // fill with spaces if string is shorter than display
		}

		data -= 0x20;
		bitfield = LCDAlphabet[data];
	
		for (i = 0; i < 16; i++)
		{
			bit = LCD1x9instance.Text[index].bit[i];
			com = LCD1x9instance.Text[index].com[i];
		
			if (bitfield & ((WORD)1 << i))
			{
				enableSegment(com, bit);
			}
			else
			{
				disableSegment(com, bit);
			}
		}
	}

	update();
}


