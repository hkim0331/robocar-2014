#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void step (void)
{
	Mtr_Run_lv(10000,-9000,0,0,0,0);
	Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void Right (void)
{
	Mtr_Run_lv(10000,0,0,0,0,0);
	Wait(180);
	Mtr_Run_lv(0,0,0,0,0,0);
	Mtr_Run_lv(10000,-9000,0,0,0,0);
	Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void Left (void)
{
	Mtr_Run_lv(0,-9000,0,0,0,0);
	Wait(180);
	Mtr_Run_lv(0,0,0,0,0,0);
	Mtr_Run_lv(10000,-9000,0,0,0,0);
	Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{
const unsigned short MainCycle = 60;
Init(MainCycle);
unsigned short left;
unsigned short right;
	int i;
	for(i=0 ;i<10000 ;i++ ){
	step();
	left = ADRead(0);
	right = ADRead(1);
	if(left>500 && right<500){
	Right();
	}else if(right>500 && left<500){
	Left();
    }else if(left>500 && right>500){
    break;
    }else{
   ;
  }
}
	return 0;
}
