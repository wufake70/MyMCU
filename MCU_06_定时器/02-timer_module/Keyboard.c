#include "Keyboard.h"
#include "Delay.h"

unsigned char KeyMonitor()
{
	if(!Btn1){
		Delay10us(1600); // 按下消抖 10ms左右
		while(Btn1==0){}
		Delay10us(1600); // 释放销抖
		return Key1;
		
	}else if(!Btn2){
		Delay10us(1600);
		while(Btn2==0){}
		Delay10us(1600);
		return Key2;
		
	}else if(!Btn3){
		Delay10us(1600);
		while(Btn3==0){}
		Delay10us(1600);
		return Key3;
		
	}else if(!Btn4){
		Delay10us(1600);
		while(Btn4==0){}
		Delay10us(1600);
		return Key4;
		
	}else{
		return Key0;
	}
}
