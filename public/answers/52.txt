#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(){
	Mtr_Run_lv(10030,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void Right(){
	Mtr_Run_lv(10030*3/4,0,0,0,0,0);
    Wait(50);
    Mtr_Run_lv(0,0,0,0,0,0);
}

void Left(){
	Mtr_Run_lv(0,-10000*3/4,0,0,0,0);
    Wait(50);
    Mtr_Run_lv(0,0,0,0,0,0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left;
	unsigned short right;
    for(;;){
    	left=ADRead(1);
    	right=ADRead(0);
     if(left>500)
    	 Left();
     if(right>500)
    	 Right();
     else
    	 step();
     if(left>500 && right>500)
    	 break;
    }
    Mtr_Run_lv(0,0,0,0,0,0);


	return 0;
}

