#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define R_power 8000
#define L_power 8000

void step(){
	Mtr_Run_lv(R_power,-L_power,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void TUR(){
	Mtr_Run_lv(-R_power, -L_power, 0, 0, 0, 0);
    Wait(100);
}

void TUL(){
	Mtr_Run_lv(R_power, L_power, 0, 0, 0, 0);
	Wait(100);
}

void WA(){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(1000);
}

void

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
	unsigned short right;

	for( ; ; )
	{
		left = ADRead(0);
		right = ADRead(1);
		if (left>500 && right>500){
			step();

		} else if (left>500 && right<500){
			TUL();
		} else if (right>500 && left<500){
			TUR();
		} else if (left>500 && right>500){
			WA();
			break;
		}
	}

	return 0;
}


