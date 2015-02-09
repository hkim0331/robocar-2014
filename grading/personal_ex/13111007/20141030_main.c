#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define right 10500
#define left  -10500
#define time  100

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for (;;){void front(void){
		Mtr_Run_lv(right,left , 0, 0, 0, 0);
			     Wait(time);
			     Mtr_Run_lv(0, 0, 0, 0, 0, 0);
			     Wait (100);
	}
	}

		return 0;
	}
