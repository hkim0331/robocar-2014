#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

		while (i<6) {
		    step();
		    Wait(500);
		    i++;

	return 0;
}

		int step(){


		}
