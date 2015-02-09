#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch)
{ // ド
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
	SO();
	RA();
	RA();
	SO();

	return 0;
}

