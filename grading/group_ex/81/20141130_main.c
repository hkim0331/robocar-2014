#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define BORDERBLACK 800
#define BORDERWHITE 400

void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
}

void soundSI(void)
{
	play(95);
}

void step(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
}

void Rkaiten(void)
{
	Mtr_Run_lv(10000,10000,0,0,0,0);
}

void Lkaiten(void)
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
}

void stop(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}

int measureblack(int blackcount)
{
	if (blackcount > 4) {
		soundSI();
		blackcount = 0;
	} else if (blackcount > 36) {
		int i = 0;
		for(i=0;i<10;i++){
			soundSI();
		}
		blackcount = 0;
	} else if (blackcount > 18 && blackcount < 36) {
		int x = 0;
		for(x=0;x<5;x++){
			soundSI();
		}
		blackcount = 0;
	} else {
		;
	}

	return blackcount;
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
	unsigned short right;

	int blacksum = 0;
	int blackcount = 0;

	for (;;)	{

			left  = ADRead(1);
			right = ADRead(0);

			if (left > BORDERBLACK && right < BORDERWHITE)	{
				Lkaiten();

			}	else if (right > BORDERBLACK && left < BORDERWHITE) {
				Rkaiten();

			}	else if (right < BORDERWHITE && left < BORDERWHITE) {
				step();

			}	else if (right > BORDERBLACK && left > BORDERBLACK) {
				blacksum += 1;
				blackcount += 1;
				step();
				Wait(500);
				measureblack(blackcount);
			}	else if (right < BORDERWHITE && left < BORDERWHITE && blacksum >= 58){
				stop();
				break;
			}
		}

	return 0;
}

