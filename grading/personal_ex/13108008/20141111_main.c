#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
#define SO 120
#define SI 95
void play(int pitch){
BuzzerSet(pitch, 100);
    BuzzerStart();
    Wait(400);
}
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);
	for(i=0,i<100,i++){
		LED(i%2 +1);
		Wait(100);

	}
	for(i=0,i<100,i++){
		play(SI);
		play(SO);
	}
	return 0;
}

