#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void){

    Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(50);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(50);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    //unsignd int ADRead(unsigned char n)
    //n=0,1;

    int i;
    for(i=0; i<10; i++){
      step();

    }
	return 0;
}

