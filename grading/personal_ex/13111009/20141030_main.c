#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define CM 70
#define PAUSE 500

#define LEFT   10000
#define RIGHT -10000

void run(short left, short right, int w, int s)
{
	Mtr_Run_lv(left, right, 0, 0, 0, 0);
	Wait(w);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(s);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
    for (i = 0; i < 10; i++) {
    	run(LEFT,RIGHT,CM,PAUSE);
    }


	return 0;
}
