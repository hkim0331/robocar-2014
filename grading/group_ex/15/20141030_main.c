#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


    void step(void){
	Mtr_Run_lv(20000,-28000,0,0,0,0);
    Wait(120);
    Mtr_Run_lv(0,0,0,0,0,0);
    Wait(1000);
    }


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


    int i;
    for(i=0;i<10;i++){
	step();
	if(ADRead(0)>256){
	break;
    }


    }

BuzzerSet(100,100);
BuzzerStart();


    return 0;
}

