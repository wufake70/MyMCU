#include "MatrixKey.h"
#include "Delay.h"

/*
行列扫描法
全部的管脚设置高电平,再将
控制第一列的p13设置0,让其
处于低电平,在而依次判断控
制各行的管脚,若S1按下,
p17和p13组成局部闭合回路,
没用电器造成局部短路,电压
为0,至此p17变为低电平

*/

char MatrixKeyMonitor()
{
	int key=Key0;
	// 扫描第一列
	P1=0xff;
	Col1=0;
	if(!Row1){Delay10us(1600);while(Row1==0);Delay10us(1600);key=Key13;}
	if(!Row2){Delay10us(1600);while(Row2==0);Delay10us(1600);key=Key9;}
	if(!Row3){Delay10us(1600);while(Row3==0);Delay10us(1600);key=Key5;}
	if(!Row4){Delay10us(1600);while(Row4==0);Delay10us(1600);key=Key1;}
	
	// 扫描第二列
	P1=0xff;
	Col2=0;
	if(!Row1){Delay10us(1600);while(Row1==0);Delay10us(1600);key=Key14;}
	if(!Row2){Delay10us(1600);while(Row2==0);Delay10us(1600);key=Key10;}
	if(!Row3){Delay10us(1600);while(Row3==0);Delay10us(1600);key=Key6;}
	if(!Row4){Delay10us(1600);while(Row4==0);Delay10us(1600);key=Key2;}
	
	// 扫描第三列
	P1=0xff;
	Col3=0;
	if(!Row1){Delay10us(1600);while(Row1==0);Delay10us(1600);key=Key15;}
	if(!Row2){Delay10us(1600);while(Row2==0);Delay10us(1600);key=Key11;}
	if(!Row3){Delay10us(1600);while(Row3==0);Delay10us(1600);key=Key7;}
	if(!Row4){Delay10us(1600);while(Row4==0);Delay10us(1600);key=Key3;}
	
	// 扫描第四列
	P1=0xff;
	Col4=0;
	if(!Row1){Delay10us(1600);while(Row1==0);Delay10us(1600);key=Key16;}
	if(!Row2){Delay10us(1600);while(Row2==0);Delay10us(1600);key=Key12;}
	if(!Row3){Delay10us(1600);while(Row3==0);Delay10us(1600);key=Key8;}
	if(!Row4){Delay10us(1600);while(Row4==0);Delay10us(1600);key=Key4;}
	
	return key;
}