#include <REGX52.H>
#include <INTRINS.H>

#define LED_PORT P2	// P2端口

void Delay(unsigned int t)	//@12.000MHz
{
	unsigned char data i, j;
	while(t>0){
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		t--;
	}
}


void main()
{
	// 流水灯，法一
	/*
	while(1)
	{
		// D0
		P2=0xFE; // 1111 1110
		Delay(500);
		P2=0xFF;
		Delay(500);
		
		// D1
		P2=0xFD; // 1111 1101
		Delay(500);
		P2=0xFF;
		Delay(500);
		
		// D2
		P2=0xFB; // 1111 1011
		Delay(500);
		P2=0xFF;
		Delay(500);
		
		// D3
		P2=0xF7; // 1111 0111
		Delay(500);
		P2=0xFF;
		Delay(500);
		
		// D4
		P2=0xEF; // 1110 1111
		Delay(500);
		P2=0xFF;
		Delay(500);
		
		// D5
		P2=0xDF; // 1101 1111
		Delay(500);
		P2=0xFF;
		Delay(500);
		
		// D6
		P2=0xBF; // 1011 1111
		Delay(500);
		P2=0xFF;
		Delay(500);
		
		// D7
		P2=0x7F; // 011 1111
		Delay(500);
		P2=0xFF;
		Delay(500);
		
	}
	*/
	// 法二
	P2=~0x01;  // ~ 表示按位取反
	Delay(500);
	while(1)
	{
		P2=~(~P2<<1);	// 左移运算符
		Delay(500);
		
		if(~P2==0x80) {
			// P2=~0x01;
			// Delay(500);
			
			while(1){
				P2=~(~P2>>1); // 右移运算符
				Delay(500);
				if(P2==~0x01) break;
			}
			
		}
	}
			
	
	
	
}