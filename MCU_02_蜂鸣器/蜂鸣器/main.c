/*
压电式蜂鸣器
	需要一定频率的脉冲信号，才能发声。(1.5k~5khz)

*/



#include <REGX52.H>

typedef unsigned int u16;	// 创建类型别名

# 定义管脚
sbit BEEP=P2^5;	// 声明一个位变量，与P2寄存器的第六位关联

void Delay10us(u16 t)	//@11.0592MHz
{
	unsigned char data i;
	while(t--){
		i = 2;
		while (--i);
	}
	
}

void main()
{
	u16 i=100;
	while(1){
	
		while(i--){
		
			// T=2ms，f=0.5khz
//			BEEP=!BEEP;
//			Delay10us(100); 
			
			// 控制声响,占空比(高电平时间)
			BEEP=0;
			Delay10us(100);
			BEEP=1;
			Delay10us(100);
			
		}
		while(1){}
	}


}