/*
LCD1602 调试工具使用
	
	some question:
		从原理图知，该工具使用用了P0组管脚(与数码管的每段LED共用管脚),
		还有P2.5~P2.7管脚(LED模块的前三个led共用管脚)

	
*/

#include <REGX52.H>
#include "LCD1602.H"

typedef unsigned char u8;
typedef unsigned int u16;

// 定义按键的管脚

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

void main()
{
	// LCD初始化 
	LCD_Init();
	LCD_ShowChar(1,1,'F');	// 单字符显示，param 行、列、字符
	LCD_ShowString(1,1,"Hello World");
	LCD_ShowNum(1,1,9999,5);	// 打印 09999,从低位开始显示，不够补0；
	LCD_ShowSignedNum(1,1,9999,5);
	LCD_Init();
	LCD_ShowHexNum(1,1,0x55,2);
	LCD_Init();
	LCD_ShowBinNum(1,1,0x5,5);

	while(1) {}
	
}
