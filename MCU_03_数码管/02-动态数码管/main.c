/*
静态数码管
	单个数码管共八段(带小数点)，从顶上逆时针数，a、b、c、d、e、f、g、dp
	dp为最高位，a为最低位。


*/


#include <REGX52.H>

typedef unsigned char u8;
typedef unsigned int u16;

// 宏定义管脚
#define SMG_A_DP_PORT P0


// 共阴数码管码表(共阳的按位取反即可),0~f外加'无显示'
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
								0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
// dp段为 P0_7,(小数点)
								
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
//	SMG_A_DP_PORT=gsmg_code[0];
	
	// 138译码器，3线(p2.4,p2.3,p2.2，表示三位二进制控制指定数码管亮灯)到8线(数码管)
	// 第4个数码管显示9
//	P2_4=1;
//	P2_3=1;
//	P2_2=1;
//	P0=gsmg_code[9];
	
	
// 动态数码管
	
	// 减少代码量
	while (1) {
		int i;
    for(i=1;i <= 8; i++) {
        P2_4 = (8-i)&4;  // 确定第三位二进制
        P2_3 = (8-i)&2;  // 确定第二位二进制
        P2_2 = (8-i)&1;  // 确定第一位二进制
        P0 = gsmg_code[i];       // 给定对应数码
				P0_7=1;
        Delay(1);
    }
	}
	
//	while(1){
//		P2_4=1;
//		P2_3=1;
//		P2_2=1;
//		P0=gsmg_code[1];
//		Delay(2);
//		
//		P2_4=1;
//		P2_3=1;
//		P2_2=0;
//		P0=gsmg_code[2];
//		Delay(2);
//		
//		P2_4=1;
//		P2_3=0;
//		P2_2=1;
//		P0=gsmg_code[3];
//		Delay(2);
//		
//		P2_4=1;
//		P2_3=0;
//		P2_2=0;
//		P0=gsmg_code[4];
//		Delay(2);
//		
//		P2_4=0;
//		P2_3=1;
//		P2_2=1;
//		P0=gsmg_code[5];
//		Delay(2);
//		
//		P2_4=0;
//		P2_3=1;
//		P2_2=0;
//		P0=gsmg_code[6];
//		Delay(2);
//		
//		P2_4=0;
//		P2_3=0;
//		P2_2=1;
//		P0=gsmg_code[7];
//		Delay(2);
//		
//		P2_4=0;
//		P2_3=0;
//		P2_2=0;
//		P0=gsmg_code[8];
//		Delay(2);
//				
//	}

	
	while(1){};



}