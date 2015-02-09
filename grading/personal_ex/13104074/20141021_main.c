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



void DO (void)
{
play(179);
}

void SO(void)
{
play(107);
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

	// ド
	    BuzzerSet(179, 100);
	    BuzzerStart();
	    Wait(400);
	    BuzzerStop();
	    Wait(100);

	    // ド
	    BuzzerSet(179, 100);
	    BuzzerStart();
	    Wait(400);
	    BuzzerStop();
	    Wait(100);

	    // ソ
	    BuzzerSet(120, 100);
	    BuzzerStart();
	    Wait(400);
	    BuzzerStop();
	    Wait(100);

	    // ソ
	    BuzzerSet(120, 100);
	    BuzzerStart();
	    Wait(400);
	    BuzzerStop();
	    Wait(100);

	    // ラ
	    BuzzerSet(107, 100);
	    BuzzerStart();
	    Wait(400);
	    BuzzerStop();
	    Wait(100);

	    // ラ
	    BuzzerSet(107, 100);
	    BuzzerStart();
	    Wait(400);
	    BuzzerStop();
	    Wait(100);

	    // ソ
	    BuzzerSet(120, 100);
	    BuzzerStart();
	    Wait(400);
	    BuzzerStop();
	    Wait(100);
	return 0;
}

