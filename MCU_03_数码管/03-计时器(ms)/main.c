/*
��ʱ��

*/


#include <REGX52.H>

typedef unsigned char u8;
typedef unsigned int u16;

// ������������(�����İ�λȡ������),0~f���'����ʾ'
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
								0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
// dp��Ϊ P0_7,(С����)
								
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

								
void setHour(u8 h);
void setMinutes(u8 m);
void setSeconds(u8 s);
void main()
{
	unsigned long time_stamp=0;
	u16 counts;
	
	
	while(1){
		// ѭ��(11*60+20)*100 ���10s(�����ֻ���ʱ��Ϊ��׼)
		// counts=100;
		counts=98;
		
		// 1��
		while(counts--){
			setHour(time_stamp/3600);
			setMinutes(time_stamp%3600/60);
			setSeconds(time_stamp%3600%60);
		
		}
		time_stamp++;
		
	}

}


void setHour(u8 h)
{
	// 6�������
	P2_4=1;
	P2_3=1;
	P2_2=0;
	P0=gsmg_code[h/10];
	Delay10us(16);
	
	// 5�������
	P2_4=1;
	P2_3=0;
	P2_2=1;
	P0=gsmg_code[h%10];
	P0_7=1;
	Delay10us(16);
}

void setMinutes(u8 m)
{
	// 4�������
	P2_4=1;
	P2_3=0;
	P2_2=0;
	P0=gsmg_code[m/10];
	Delay10us(16);
	
	// 3�������
	P2_4=0;
	P2_3=1;
	P2_2=1;
	P0=gsmg_code[m%10];
	P0_7=1;
	Delay10us(16);
}

void setSeconds(u8 s)
{
	// 2�������
	P2_4=0;
	P2_3=1;
	P2_2=0;
	P0=gsmg_code[s/10];
	Delay10us(16);
	
	// 1�������
	P2_4=0;
	P2_3=0;
	P2_2=1;
	P0=gsmg_code[s%10];
//	P0_7=1;
	Delay10us(20);
	
}



