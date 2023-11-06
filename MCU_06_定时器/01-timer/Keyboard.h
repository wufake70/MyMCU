#include <REGX52.H>
#ifndef KEYBOARD_H
#define KEYBOARD_H

// 定义按键的管脚
sbit Btn1=P3^1;
sbit Btn2=P3^0;
sbit Btn3=P3^2;
sbit Btn4=P3^3;

// 宏定义按键的序号
#define Key0 0	// 无按键按下
#define Key1 1
#define Key2 2
#define Key3 3
#define Key4 4

unsigned char KeyMonitor();

#endif