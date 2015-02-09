#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch){
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(400);
}
void DO(void){
	play(179);
}
void SO(void){
	play(120);
}
void RA(void){
	play(107);
}
void RE(void){
	play(160);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int t=400;


	DO();
	DO();
	SO();
	SO();
	RA();
	RA();
	SO();



	BuzzerSet(134,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(142,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(160,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(179,100);
	BuzzerStart();
	Wait(2*t);
	BuzzerStop();
	Wait(t);



	BuzzerSet(120,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(134,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(142,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(160,100);
	BuzzerStart();
	Wait(2*t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(120,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(134,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(142,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(160,100);
	BuzzerStart();
	Wait(2*t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(179,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(120,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(107,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(120,100);
	BuzzerStart();
	Wait(2*t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(134,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(142,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(160,100);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);
	BuzzerStart();
	Wait(t);
	BuzzerStop();
	Wait(t);

	BuzzerSet(179,100);
	BuzzerStart();
	Wait(2*t);
	BuzzerStop();
	Wait(t);


	return 0;
}

