#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void play1 (){
	BuzzerSet(142,100);
	BuzzerStart();
}
void play2 (){
	BuzzerSet(179,100);
	BuzzerStart();
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	LED(3);
	Wait(1000);
	int i;
	for(i=0;i<100;i++){
		LED((i%2)+1);
		Wait(1000);
	}

	return 0;
}

