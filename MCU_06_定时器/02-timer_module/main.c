/*
main函数while循环监控独立按键，控制流水灯方向

定时器中断函数执行流水灯

*/

#include <REGX52.H>
#include "Timer.h"
#include "Keyboard.h"

char turn=0;
int main()
{
	P2=0xfe;
	Timer0_Init();
	
	while(1)
	{
		switch(KeyMonitor())
		{
			case 0:break;
			case 1:turn=!turn;break;
			case 2:turn=!turn;break;
			case 3:turn=!turn;break;
			case 4:turn=!turn;break;
		}
	
	}

	return 0;
}

void Timer0_Isr(void) interrupt 1
{
	static unsigned int T0Count=0;
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	T0Count++;
	if(T0Count>=1000){
		T0Count=0;
//		if(P2==0xfe) P2=0x7f;
		if(~P2==0x80&turn==0)
			{ 
				P2=0xfe;
			}else if(~P2==0x01&turn==1){
				P2=0x7f;
			}else if(turn==0){
				P2=~(~P2<<1);
			}else{
				P2=~(~P2>>1);
			}
		
	}
}
