#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int k;
int l;

void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(400);
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


	for(k=0;k<=1;k++){
		BuzzerSet(134,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}
	for(k=0;k<=1;k++){
		BuzzerSet(142,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}
	for(k=0;k<=1;k++){
		BuzzerSet(160,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}

	BuzzerSet(179,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(500);

	for(l=0;l<=1;l++){
	for(k=0;k<=1;k++){
		BuzzerSet(120,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}
	for(k=0;k<=1;k++){
		BuzzerSet(134,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}
	for(k=0;k<=1;k++){
		BuzzerSet(142,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}

	BuzzerSet(160,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(500);
	}

	for(k=0;k<=1;k++){
		BuzzerSet(179,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}
	for(k=0;k<=1;k++){
		BuzzerSet(120,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}
	for(k=0;k<=1;k++){
		BuzzerSet(107,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}

	BuzzerSet(120,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(500);

	for(k=0;k<=1;k++){
		BuzzerSet(134,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}
	for(k=0;k<=1;k++){
		BuzzerSet(142,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}
	for(k=0;k<=1;k++){
		BuzzerSet(160,100);
		BuzzerStart();
		Wait(200);
		BuzzerStop();
		Wait(200);
	}

	BuzzerSet(179,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(500);

	return 0;
}

