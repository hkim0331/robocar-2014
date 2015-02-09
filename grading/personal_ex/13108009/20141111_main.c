#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO 120
#define SHI 95

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);
	Wait(1000);
	for(i=0;i<10;i++){
		LED( (i % 2) + 1);
		BuzzerSet(95,100);
			BuzzerStart();
			Wait(150);
			BuzzerStop();
			Wait(50);
		Wait(400);
		LED( (i % 2) + 2);
		BuzzerSet(120,100);
			BuzzerStart();
			Wait(150);
			BuzzerStop();
			Wait(50);
		Wait(400);
	}
	LED(0);
	return 0;
}

