#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(300);
	BuzzerStop();
	Wait(100);
}

void DO(void)
{
	play(179);
}

void RE(void)
{
	play(160);
}

void MI(void)
{
	play(142);
}

void FA(void)
{
	play(134);
}

void SO(void)
{
	play(120);
}

void RA(void)
{
	play(107);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	DO();
	DO();
	SO();
	SO();
	RA();
	RA();
	SO();

	BuzzerSet(179,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(179,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(120,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(120,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(107,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(107,100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
		BuzzerSet(120,100);
		BuzzerStart();
		Wait(600);
		BuzzerStop();
		Wait(300);

		BuzzerSet(134,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(134,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(142,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(142,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(160,100);
		BuzzerStart();
		Wait(300);
		BuzzerStop();
		Wait(100);
		BuzzerSet(160,100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
		BuzzerSet(179,100);
		BuzzerStart();
		Wait(600);
		BuzzerStop();
		Wait(300);


	return 0;
}

