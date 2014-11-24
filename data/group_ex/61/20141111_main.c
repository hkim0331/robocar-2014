#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
int i;
unsigned short left;
unsigned short right;

void step(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void exp1(){//30°左回転

	Mtr_Run_lv(10000,10000,0,0,0,0);
		Wait(158);
		Mtr_Run_lv(0,0,0,0,0,0);

}

void exp2(){//30° 右回転

	Mtr_Run_lv(-10000,-10000,0,0,0,0);
		Wait(158);
		Mtr_Run_lv(0,0,0,0,0,0);

}

void gr1(void){
	for( ; ; ){
		step();
        Wait(50);
		left = ADRead(0);
		right = ADRead(1);
	if(left<500 && right<500){
		;
	}else if(left>700 && right<400){
		exp1();
	}else if(left<400 && right>700){
		exp2();
	}else if(left>700 && right>700){
		break;

	}

	}
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	gr1();


	return 0;
}

