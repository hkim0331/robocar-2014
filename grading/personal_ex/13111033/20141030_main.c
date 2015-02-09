#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define EDGE 1
#define N 20

	unsigned int ADRead(unsinged char n)
	n=0,1
	0~1023

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	  int i;
	  for (i = 0; i < N; i++) {


	Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
		Wait(50);
		Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	  }
	return 0;
}

