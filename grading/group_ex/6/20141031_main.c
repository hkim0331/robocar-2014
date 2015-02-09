#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define CM 70
#define PAUSE 500

#define LEFT 10000
#define RIGHT -10800

void run(short left, short right, int s, int s2)
{
	Mtr_Run_lv(left,right,0, 0, 0,0);
	Wait(s);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(s2);

	}


int main(void)
{

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	unsigned short x;

	for(i=0;i<10000;i++){
		run(LEFT,RIGHT,CM,PAUSE);
		x = ADRead(0);
		if (x>100) {BuzzerSet(100,100);
		BuzzerStart();Wait(5000000);  }else{

		}

	}

	return 0;
}

