#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

//カエルの歌
#define DURATION 400
#define PAUSE 100
#define VOL 100

#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define NN    1
#define XX    0

void play(int pitch,int wait)
{
	if (pitch==1) {
		BuzzerStop();
		Wait(DURATION + PAUSE);
	} else {
		BuzzerSet(pitch, 100);
		BuzzerStart();
		Wait(wait);
		BuzzerStop();
		Wait(100);
	}
}

void kaeru(void)
{
	int s[] = {DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,RA,SO,FA,MI,NN,DO,NN,DO,NN,DO,NN,DO,NN,XX};
	int t[] = {DO,DO,RE,RE,MI,MI,FA,FA,XX};
	int u[] = {MI,RE,DO,XX};
	int i;

	for(i=0; s[i]!=XX; i++)
	{
		play(s[i],400);
	}
	for(i=0; t[i]!=XX; i++)
	{
		play(t[i],150);
	}
	for(i=0; u[i]!=XX; i++)
	{
		play(u[i],400);
	}
}
//カエルの歌

void mtr(int mtrL, int mtrR)
{
	Wait(1000);
	Mtr_Run_lv(mtrL, mtrR, 0, 0, 0, 0);
	Wait(50);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(1000);
}

void go(void)
{
	mtr(10000,-10000);
}


void forward(int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		go();
		if(500 < ADRead(0))
		{
			break;
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	forward(10);
	kaeru();

	return 0;
}
