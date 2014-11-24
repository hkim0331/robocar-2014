#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void ex1(void)
{  Mtr_Run_lv(10000,-10000,0,0,0,0);//1センチ前進、停止
Wait(160);
Mtr_Run_lv(0,0,0,0,0,0);
}

void ex2(void)
{  Mtr_Run_lv(10000,-10000,0,0,0,0);//10センチ前進、停止
Wait(900);
Mtr_Run_lv(0,0,0,0,0,0);
}

void ex3(void)
{  Mtr_Run_lv(10000,-10000,0,0,0,0);//5センチ後退、停止
Wait(900);
Mtr_Run_lv(0,0,0,0,0,0);
}

void ex4(void)
{  Mtr_Run_lv(-10000,-10000,0,0,0,0);//右に90度回転、静止
Wait(500);
Mtr_Run_lv(0,0,0,0,0,0);
}

void ex5(void)
{  Mtr_Run_lv(10000,-10000,0,0,0,0);//左に360度回転、静止
Wait(2720);
Mtr_Run_lv(0,0,0,0,0,0);
}

void ex6(void)
{  Mtr_Run_lv(10000,-10000,0,0,0,0);//30センチ前進、静止
Wait(2700);
Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    ex6();
    ex4();
    ex6();
    ex4();
    ex6();
    ex4();
    ex6();
	return 0;
}
