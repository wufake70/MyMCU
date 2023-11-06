/*
矩阵键盘
	优点
		多个按键时，可以减少io口的使用，该模块只占用了8GPIO，
		将每一行按键的引脚(pad)串接在一个gpio，
		将每一列按键的引脚(pad)串接在一个gpio。

按键扫描
	按列扫描
	按行扫描
		行列扫描法
		全部的管脚设置高电平,再将
		控制第一列的p13设置0,让其
		处于低电平,在而依次判断控
		制各行的管脚,若S1按下,
		p17和p13组成局部闭合回路,	
		没用电器造成局部短路,电压
		为0,至此p17变为低电平
	
*/

#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.H"
#include "MatrixKey.h"

typedef unsigned char u8;
typedef unsigned int u16;

// 定义按键的管脚 P1组,P1.0~P1.3控制列，P1.4~P1.7控制行


void main()
{
	LCD_Init();
	while(1)
	{
		switch(MatrixKeyMonitor())
		{
			case 1:
				LCD_Init();
				LCD_ShowString(1,1,"1");
				break;
			case 2:
				LCD_Init();
				LCD_ShowString(1,1,"2");
				break;
			case 3:
				LCD_Init();
				LCD_ShowString(1,1,"3");
				break;
			case 4:
				LCD_Init();
				LCD_ShowString(1,1,"4");
				break;
			case 5:
				LCD_Init();
				LCD_ShowString(1,1,"5");
				break;
			case 6:
				LCD_Init();
				LCD_ShowString(1,1,"6");
				break;
			case 7:
				LCD_Init();
				LCD_ShowString(1,1,"7");
				break;
			case 8:
				LCD_Init();
				LCD_ShowString(1,1,"8");
				break;
			case 9:
				LCD_Init();
				LCD_ShowString(1,1,"9");
				break;
			case 10:
				LCD_Init();
				LCD_ShowString(1,1,"10");
				break;
			case 11:
				LCD_Init();
				LCD_ShowString(1,1,"11");
				break;
			case 12:
				LCD_Init();
				LCD_ShowString(1,1,"12");
				break;
			case 13:
				LCD_Init();
				LCD_ShowString(1,1,"13");
				break;
			case 14:
				LCD_Init();
				LCD_ShowString(1,1,"14");
				break;
			case 15:
				LCD_Init();
				LCD_ShowString(1,1,"15");
				break;
			case 16:
				LCD_Init();
				LCD_ShowString(1,1,"16");
				break;
			
			default:
			{}
		}
	}
}
