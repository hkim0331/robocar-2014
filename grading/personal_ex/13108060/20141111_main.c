#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(500);
	BuzzerStop();
	Wait(100);
}

void SO(void)
{
	play(120);
}
void SI(void)
{
	play(95);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(1);
	Wait(1000);
	for (i=0; i<10; i++) {
        LED( ( i % 2 ) + 1 );
        Wait(100);
        SI();
    }


	LED(2);
	Wait(1000);
	for (i=0; i<10; i++) {
        LED( ( i % 2 ) + 1 );
        Wait(100);
        SO();
    }
	LED(0);

	return 0;
}

