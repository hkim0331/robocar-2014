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

void play(){
	BuzzerSet(95, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
	unsigned short right;

	int i,j;

	LED(1);
	for (i=0; i<6; i++){
		for( ; ; ){
			left = ADRead(0);
			right = ADRead(1);
			if (left<500 && right<500){
				step();
			} else if (left<500 && right>500){
				TUR();
			} else if (right<500 && left>500){
				TUL();
			} else if (left>500 && right>500){
				WA();
				break;
			}
		}
		LED(2);
		for( ; ; ){
			left = ADRead(0);
			right = ADRead(1);
			if (left>500 && right>500){
				step();
			} else if (left<500 && right>500){
				TUR();
			} else if (right<500 && left>500){
				TUL();
			} else if (left<500 && right<500){
				WA();
				break;
			}
		}
		LED(3);


	}
	return 0;
}


