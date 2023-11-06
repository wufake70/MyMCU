#include "Time.h"
#include <REGX52.H>

void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	// AUXR &= 0x7F;			//定时器时钟12T模式
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
	EA=1;						//允许总中断
	PT0=0;					//中断优先级
}
/* 中断操作模板
void Timer0_Isr(void) interrupt 1
{
	static unsigned int T0Count=0;
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	T0Count++;
	if(T0Count>=1000){
		T0Count=0;
		P2_0=~P2_0;	// 中断后操作
	}
}
*/



void Timer1_Init(void)		//1毫秒@11.0592MHz
{
	// AUXR &= 0xBF;			//定时器时钟12T模式
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x10;			//设置定时器模式
	TL1 = 0x66;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
	ET1 = 1;				//使能定时器1中断
	EA=1;						//允许总中断
	PT0=0;					//中断优先级
}

/* 中断操作模板
void Timer1_Isr(void) interrupt 3
{
	static unsigned int T1Count=0;
	TL1 = 0x66;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	T1Count++;
	if(T1Count>=1000){
		T1Count=0;
		P2_4=~P2_4; // 中断后操作
	}
}
*/