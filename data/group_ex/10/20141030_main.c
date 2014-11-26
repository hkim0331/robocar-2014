#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short ADRead(unsigned char n);

	int i;
	unsigned short bw;

	for (i = 0; i<100; i++) {
		Mtr_Run_lv(1000,-1000,0,0,0,0);
		Wait(100);
		Mtr_Run_lv(0,0,0,0,0,0);
		Wait(100);
		bw = ADRead(0);
		if(bw > 100) {
			break;
		} else{
			;
		}

	}

	BuzzerSet(100,100);
	BuzzerStop();
	return 0;
}

