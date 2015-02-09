#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(10);
}

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define NN 0
#define XX (-1)


void kaerunouta(void)
{
	int notes[]={DO,NN,RE,NN,MI,NN,FA,NN,MI,NN,RE,NN,DO,NN,NN,
			MI,NN,FA,NN,SO,NN,RA,NN,SO,NN,FA,NN,MI,NN,NN,
			DO,NN,NN,NN,DO,NN,NN,NN,DO,NN,NN,NN,DO,NN,NN,NN,
			DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,XX};
	int i;

	for(i=0; notes[i] !=XX; i++)
	{
		play(notes[i]);
	}
}

int step(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(500);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(55);
	Mtr_Run_lv(0,0,0,0,0,0);

	return 0;
}

int step1(void)
{
	int i;
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	for(i=0;i<6;i++)
	{
		step();
	}

	return 0;
}

int step2(void)
{
	const unsigned short MainCycle = 60;
	unsigned short left;
	Init(MainCycle);
	for( ; ; )
	{
		if(600<left && left<1000)
			kaerunouta();
		else
			step();
	}

	return 0;
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	step2();

	return 0;
}
