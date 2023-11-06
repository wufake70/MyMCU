#include <REGX52.H>
#include "delay.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

#define matrix_led_port   P0

void _74HC595_writebyte(unsigned char byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
			SER=byte&(0x80>>i);
			SCK=1;
			SCK=0;
	}
	  RCK=1;
		RCK=0;

}

void matrix_init()
{
		SCK=0;
	RCK=0;
}

void matrix_showcol(unsigned char col,Data)
{
		_74HC595_writebyte(Data);
		matrix_led_port=~(0X80>>col);
		delay(1);
		matrix_led_port=0XFF;
}