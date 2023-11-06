#include "Delay.h"

void Delay(unsigned int t)	//@11.0592MHz 1ms
{
	unsigned char data i, j;
	while(t>0){
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		t--;
	}
}

void Delay10us(unsigned int t)	//@11.0592MHz 1us
{
	unsigned char data i;
	while(t>0){
		i = 25;
		while (--i);
		t--;
	}
}			