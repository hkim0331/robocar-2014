#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DURATION 400
#define PAUSE 100

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95

#define XX (-1)

int duration;
int pause;
int sec;

void step(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(80);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void play(int pitch, int sec)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(300);
	BuzzerStop();
	Wait(sec);
}

void music(int notes[])
{
	int i;

	for(i=0;notes[i]!=XX;i++){
		play(notes[i],sec);
	}
}

void kaeru(void)
{
	int notes1[]={DO,RE,MI,FA,MI,RE,DO,
					MI,FA,SO,RA,SO,FA,MI,
					DO,DO,DO,DO,XX};
	int notes2[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};
	int notes3[]={MI,RE,DO,XX};

	sec = 150;
	music(notes1);

	duration = DURATION/2;
	Wait(duration);
	pause    = PAUSE/2;
	Wait(pause);

	sec = 75;
	music(notes2);

	sec = 150;
	music(notes3);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	unsigned short left;
	unsigned short right;

	for (i=0;i<10000;i++)	{

		step();
		Wait(500);
		left = ADRead(1);
		right = ADRead(0);


		if (left > 800 || right > 800)	{
			break;

		} else{
			;
		}
	}

	kaeru();

	return 0;
}

