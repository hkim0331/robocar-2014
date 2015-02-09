#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SI 95
#define SO 120


void play(int pitch)
{
	BuzzerSet(pitch,500);
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
    Wait(100);
}









int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	for (i=0; i<10; i++){
		LED( (i % 2) +1);       //一マス空けた方が見やすいよ//
		Wait(100);

	}

	if((i%2)==0);
       play(95);
	else
	   play(120);



	LED(0);

	return 0;
}

