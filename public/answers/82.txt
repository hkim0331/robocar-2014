#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int step1()
{
	Mtr_Run_lv(13000,-12000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
}

int step2()
{
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int step3()
{
	Mtr_Run_lv(9000,10000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	step1();
}

int step4()
{
	Mtr_Run_lv(-11000,-10000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	step1();
}

int step()
{
	unsigned short left,right;
	int i;
	for( ; ; ) {
		step1();
		Wait(50);
		left=ADRead(0);
		right=ADRead(1);
		if(400<left){break;
		}
		else if(500<right){break;
		}
		else if(500<right && 500<left){break;
		}
		else{;}
	}
	if(500<right && 500<left){
		step2();
	}else if(500<right){
		step4();
	}else if(500<left){
		step3();
	}else{;}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	step();

	return 0;
}
