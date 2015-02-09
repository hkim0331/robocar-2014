#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch)
{
    BuzzerSet(pitch, 100);
    BuzzerStart();
    Wait(400);
    BuzzerStop();
    Wait(100);
}
void DO(void)
{
    play(179);
}
void SO(void)
{
    play(120);
}
void RA(void)
{
    play(107);
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


	return 0;
}

