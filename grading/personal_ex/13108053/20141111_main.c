#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	int i;
	for (i=0; i<100; i++){
	BuzzerSet(95,100);
	BuzzerStart();
	LED(1);
		Wait(1000);
		BuzzerStop();
		BuzzerSet(120,100);
			BuzzerStart();
			LED(2);
			Wait(1000);
			BuzzerStop();
	}
	LED(0);
	return 0;
}

