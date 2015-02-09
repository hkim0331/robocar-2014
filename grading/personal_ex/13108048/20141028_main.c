#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void exp1(){

	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(5000);
	Mtr_Run_lv(0,0,0,0,0,0);


}

void exp2(){

	Wait(2000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(5000);
	Mtr_Run_lv(0,0,0,0,0,0);

}

void exp3(){

	Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(60);
		Mtr_Run_lv(0,0,0,0,0,0);


}

void exp4(){

	Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(600);
		Mtr_Run_lv(0,0,0,0,0,0);

}

void exp5(){

	Mtr_Run_lv(-10000,10000,0,0,0,0);//koutai
		Wait(300);
		Mtr_Run_lv(0,0,0,0,0,0);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

 exp3();

	return 0;
}

