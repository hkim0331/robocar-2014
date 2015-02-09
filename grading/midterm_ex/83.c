#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    unsigned short right;
    unsigned short left;


    while(1){

    right = ADRead(1);
    left = ADRead(0);

    if((right<500)&&(left<500)){
    Mtr_Run_lv(5000,-5000,0,0,0,0);
    Wait(100);
    }
    else if((right<500)&&(left>500)){
        Mtr_Run_lv(8000,-2000,0,0,0,0);
        Wait(100);
    }
    else if((right>500)&&(left<500)){
        Mtr_Run_lv(2000,-8000,0,0,0,0);
        Wait(100);
    }
    else{
    	break;
    }
    }
    Mtr_Run_lv(0,0,0,0,0,0);
	return 0;

}
