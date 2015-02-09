#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch)
{
	      BuzzerSet(pitch, 100); // ピッチ 120、ボリュームは 100 だ。
		  BuzzerStart();       // ブザー鳴れ。
		  Wait(100);          // 3秒待つ。
		  BuzzerStop();        // 鳴りやめ。
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

void FA(void)
{

	play(134);
}

void MI(void)
{

	play(142);
}

void RE(void)
{

	play(160);
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

