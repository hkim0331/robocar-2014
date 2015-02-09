#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void fw(void)
{
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
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

    unsigned short bw;

    int i;
    for(i=0; i<100; i++){
	fw();
	stop();
	bw=ADRead(0);
	if(bw>500){
		break;
	}	else	{
		;

	}
    }
    BuzzerSet(100,100);
    BuzzerStart();
	return 0;
}

