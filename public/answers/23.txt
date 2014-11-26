#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int bwL;
int bwR;

#define bwL ADRead(0)
#define bwR ADRead(1)

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

void mtr(int mtrL, int mtrR)
{
	Wait(50);
	Mtr_Run_lv(mtrL, mtrR, 0, 0, 0, 0);
	Wait(100);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void go()
{
	mtr(7000, -7000);
	LED(1);
}

void stop()
{
	mtr(0,0);
	LED(2);
}

void right()
{
	mtr(0,-7000);
}

void left()
{
	mtr(7000,0);
}

void turnR(int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		right();
		if((bwR < 500) || (500 < bwL))
		{
			break;
		}
	}
}

void turnL(int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		left();
		if((500 < bwL) || (500 < bwR))
		{
			break;
		}
	}
}

void step(int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		if((bwL < 500) && (bwR < 500))
		{
			go();
		}
		if((bwL < 500) && (500 < bwR))
		{
			turnR(10000);
		}
		if((500 < bwL) && (bwR < 500))
		{
			turnL(10000);
		}
		if((500 < bwL) && (500 < bwR))
		{
			break;
		}
	}
	stop();
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	step(10000);
	kaeru();
	LED(0);

	return 0;
}
