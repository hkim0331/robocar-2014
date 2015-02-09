#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(250);
	BuzzerStop();
	Wait(100);
}
void main DO(void)
{
	play(179);
}
void main RE(void)
{
	play(160);
}
void main MI(void)
{
	play(142);
}
void main FA(void)
{
	play(134);
}
void main SO(void)
{
	play(120);
}
void main RA(void)
{
	play(107);
}
void main SI(void)
{
	play(95);
}
void main DO(void)
{
	play(90);
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

