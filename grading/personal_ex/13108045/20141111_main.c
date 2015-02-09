#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(800);
	int i;
	for(i=0; i<8; i++){
		LED((i % 2) + 1);
Wait(300);
	}
	LED(0);


	  BuzzerSet(120, 100);
	  BuzzerStart();
	  Wait(3000);
	  BuzzerStop();



	return 0;
}




