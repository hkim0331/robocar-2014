#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	int i;
	LED(3);

	for (i=0;i<30;i++);
	   LED(1);
	   LED(2);

	 LED(0);


	return 0;
}

