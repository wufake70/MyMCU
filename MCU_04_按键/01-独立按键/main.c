/*
独立按键
	按键的按下(释放)抖动，此时会产生连续的不可控制的高低电平信号，需要消除抖动。
	
	软件消抖
	硬件消抖
	
*/

#include <REGX52.H>

typedef unsigned char u8;
typedef unsigned int u16;

// 定义按键的管脚
sbit Btn1=P3^1;
sbit Btn2=P3^0;
sbit Btn3=P3^2;
sbit Btn4=P3^3;

// 宏定义按键的序号
#define Key0 0	// 无按键按下
#define Key1 1
#define Key2 2
#define Key3 3
#define Key4 4

#define LED1 P2_0
#define LED2 P2_1
#define LED3 P2_2
#define LED4 P2_3
								
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

// 按键监测
u8 buttonMonitor()
{
	if(!Btn1){
		Delay10us(1600); // 按下消抖 10ms左右
		while(Btn1==0){}
		Delay10us(1600); // 释放销抖
		return Key1;
		
	}else if(!Btn2){
		Delay10us(1600);
		while(Btn2==0){}
		Delay10us(1600);
		return Key2;
		
	}else if(!Btn3){
		Delay10us(1600);
		while(Btn3==0){}
		Delay10us(1600);
		return Key3;
		
	}else if(!Btn4){
		Delay10us(1600);
		while(Btn4==0){}
		Delay10us(1600);
		return Key4;
		
	}else{
		return Key0;
	}
}							
								
void main()
{
	while(1){
		switch(buttonMonitor())
		{
			case 0:
				break;
			case 1:
				LED1=!LED1;
				break;
			case 2:
				LED2=!LED2;
				break;
			case 3:
				LED3=!LED3;
				break;
			case 4:
				LED4=!LED4;
				break;
			default:
				break;
		}
	}
}
