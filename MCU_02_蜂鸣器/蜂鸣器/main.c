/*
ѹ��ʽ������
	��Ҫһ��Ƶ�ʵ������źţ����ܷ�����(1.5k~5khz)

*/



#include <REGX52.H>

typedef unsigned int u16;	// �������ͱ���

# ����ܽ�
sbit BEEP=P2^5;	// ����һ��λ��������P2�Ĵ����ĵ���λ����

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
		
			// T=2ms��f=0.5khz
//			BEEP=!BEEP;
//			Delay10us(100); 
			
			// ��������,ռ�ձ�(�ߵ�ƽʱ��)
			BEEP=0;
			Delay10us(100);
			BEEP=1;
			Delay10us(100);
			
		}
		while(1){}
	}


}