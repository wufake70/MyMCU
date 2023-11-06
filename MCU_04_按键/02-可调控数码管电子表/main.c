// 可调控的数码管电子表
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
sbit Btn1=P3^1;	// 时针键
sbit Btn2=P3^0; // 分针键
sbit Btn3=P3^2; // 秒针键
sbit Btn4=P3^3;	// 开始/暂停键

// 宏定义按键的序号
#define Key0 0	// 无按键按下
#define Key1 1
#define Key2 2
#define Key3 3
#define Key4 4

// 共阴数码管码表(共阳的按位取反即可),0~f外加'无显示'
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
								0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
// dp段为 P0_7,(小数点)
								
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
		Delay10us(3300); // 等待抖动结束，至少30ms
		return Key1;
		
	}else if(!Btn2){
		Delay10us(3300);
		return Key2;
		
	}else if(!Btn3){
		Delay10us(3300);
		return Key3;
		
	}else if(!Btn4){
		Delay10us(30000);
		return Key4;
		
	}else{
		return Key0;
	}
	
}
							
void setHour(u8 h);
void setMinutes(u8 m);
void setSeconds(u8 s);

void main()
{
	//运行前设置当前时间
	unsigned long time_stamp=0;
	u16 counts;
	u8 is_run=0;
	
	u8 hour_counts=0;
	u8 minute_counts=0;
	u8 second_counts=0;
	
	while(1){
		switch(buttonMonitor())
		{
			case 0:
				if(!is_run){
					setHour(time_stamp/3600);
					setMinutes(time_stamp%3600/60);
					setSeconds(time_stamp%3600%60);
					break;
				}
				// 循环(11*60+20)*100 落后10s(假设手机定时器为标准)
				// counts=100;
				counts=98;
				
				// 1秒
				while(counts--){
					setHour(time_stamp/3600);
					setMinutes(time_stamp%3600/60);
					setSeconds(time_stamp%3600%60);
				
				}
				time_stamp++;
				if(time_stamp==86400) time_stamp=0;
				break;
			case 1:	// 调整时针键
				hour_counts++;
				if(hour_counts==24) {
					time_stamp=0;
				}else{
					time_stamp+=3600;
				}
				break;
			case 2:
				minute_counts++;
				time_stamp+=60;
				break;
			case 3:
				second_counts++;
				time_stamp+=1;
				break;
			case 4:		// 暂停时需长按 1s
				is_run=!is_run;
				break;
			default:
				break;
		}
	}
}


void setHour(u8 h)
{
	// 6号数码管
	P2_4=1;
	P2_3=1;
	P2_2=0;
	P0=gsmg_code[h/10];
	Delay10us(16);
	
	// 5号数码管
	P2_4=1;
	P2_3=0;
	P2_2=1;
	P0=gsmg_code[h%10];
	P0_7=1;
	Delay10us(16);
}

void setMinutes(u8 m)
{
	// 4号数码管
	P2_4=1;
	P2_3=0;
	P2_2=0;
	P0=gsmg_code[m/10];
	Delay10us(16);
	
	// 3号数码管
	P2_4=0;
	P2_3=1;
	P2_2=1;
	P0=gsmg_code[m%10];
	P0_7=1;
	Delay10us(16);
}

void setSeconds(u8 s)
{
	// 2号数码管
	P2_4=0;
	P2_3=1;
	P2_2=0;
	P0=gsmg_code[s/10];
	Delay10us(16);
	
	// 1号数码管
	P2_4=0;
	P2_3=0;
	P2_2=1;
	P0=gsmg_code[s%10];
//	P0_7=1;
	Delay10us(20);
	
}


