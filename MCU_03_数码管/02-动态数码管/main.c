/*
��̬�����
	��������ܹ��˶�(��С����)���Ӷ�����ʱ������a��b��c��d��e��f��g��dp
	dpΪ���λ��aΪ���λ��


*/


#include <REGX52.H>

typedef unsigned char u8;
typedef unsigned int u16;

// �궨��ܽ�
#define SMG_A_DP_PORT P0


// ������������(�����İ�λȡ������),0~f���'����ʾ'
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
								0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
// dp��Ϊ P0_7,(С����)
								
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
	
	// 138��������3��(p2.4,p2.3,p2.2����ʾ��λ�����ƿ���ָ�����������)��8��(�����)
	// ��4���������ʾ9
//	P2_4=1;
//	P2_3=1;
//	P2_2=1;
//	P0=gsmg_code[9];
	
	
// ��̬�����
	
	// ���ٴ�����
	while (1) {
		int i;
    for(i=1;i <= 8; i++) {
        P2_4 = (8-i)&4;  // ȷ������λ������
        P2_3 = (8-i)&2;  // ȷ���ڶ�λ������
        P2_2 = (8-i)&1;  // ȷ����һλ������
        P0 = gsmg_code[i];       // ������Ӧ����
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