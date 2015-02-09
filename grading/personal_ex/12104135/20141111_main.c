#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO    179
#define MI    142


int music(int i){
	BuzzerSet(i, 100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);

	int i;
	for(i=0; i<100; i++){
		if((i % 2) + 1 == 1){
			LED((i % 2) + 1);
			music(142);
		} else {
			LED((i % 2) + 1);
			music(179);
		}
		Wait(100);
	}

	LED(0);

	return 0;
}
