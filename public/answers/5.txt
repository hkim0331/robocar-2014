#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void fw(void)
{
	Mtr_Run_lv(7000, -7300, 0, 0, 0, 0);
	Wait(100);
}

void turnR(void)
{
	Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
	Wait(100);
}

void turnL(void)
{
	Mtr_Run_lv(0, -10000, 0, 0, 0, 0);
	Wait(100);
}

void stop(void)
{
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(100);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    unsigned short ADRead(unsigned char n);

    unsigned short r,l;

    int i;
    for(i=0; i<1000; i++){
	fw();
	r=ADRead(0);
	l=ADRead(1);
	if((r>500) && (l>500)){

	    stop();
		Wait(10000);
	}   else if(l>500)	{
		turnL();
		LED(1);
	}   else if(r>500){
		turnR();
		LED(2);
	}
    }


	Wait(10000);
	return 0;
}

