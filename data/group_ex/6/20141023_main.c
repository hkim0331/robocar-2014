#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define A 10000
#define B 20000
#define C 30000
#define D 0
#define E -10000
#define DURATION 2083
#define DURATION2 500

void run(short left, short right,unsigned int w)
{
	Mtr_Run_lv(left, right, 0, 0, 0, 0);
	Wait(w);
	Mtr_Run_lv(0,0,0,0,0,0);
}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run(10000,-10000,2083);
	run(10000,10000,500);
	run(10000,-10000,2083);
	run(10000,10000,500);
	run(10000,-10000,2083);
	run(10000,10000,500);
	run(10000,-10000,2083);



	return 0;
}

