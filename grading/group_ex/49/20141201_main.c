#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define R_power 3000
#define L_power 3000

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
	left = ADRead(0);
	right = ADRead(1);
	int i,j;
	int blacks;
	blacks = 0;

	for (i=0; i<3; i++){
	for( ; ; ){
		if (left<500 && right<500){
			step();
			blacks=0;
		} else if (left<500 && right>500){
			TUR();
		} else if (right<500 && left>500){
			TUL();
		} else if (left>500 && right>500){
			WA();
			break;
		}
	}

	for( ; ; ){
		if (left>500 && right>500){
		    step();
			blacks +=1;
		} else if (left<500 && right>500){
			TUR();
		} else if (right<500 && left>500){
			TUL();
		} else if (left<500 && right<500){
			WA();
			break;
		}
	}

	for(j=0;j<blacks;j++){
		play();
	}

	}
	return 0;
}
