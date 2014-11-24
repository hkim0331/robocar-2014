#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 9990
#define FW 50
#define N 20
#define CM 50

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
#define NN    0

#define XX    (-1)

void play(int pitch,int wait)
{
	if (pitch==NN) {
		BuzzerStop();
		Wait(DURATION+PAUSE);
	} else {
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(wait);
		BuzzerStop();
		Wait(PAUSE);
	}
}

void kaeru(void)
{
	int i;
	int s[]={DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,RA,SO,FA,MI,NN,DO,NN,DO,NN,DO,NN,DO,NN,XX};
	int t[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};
	int u[]={MI,NN,RE,NN,DO,XX};

	for(i=0;s[i]!=XX;i++)
	{
		play(s[i],400);
	}
	for(i=0;t[i]!=XX;i++)
	{
		play(t[i],200);
	}
	for(i=0;u[i]!=XX;i++)
	{
		play(u[i],200);
	}
}

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(int i)
{
	motor(0, 0);
	Wait(1000*i);
}

void step(short s)
{
	motor(LEFT,RIGHT);
	Wait(CM*s);
	stop(1);
}

void step2(void){
	int i;
	unsigned short bw;
	for (i = 0; i < N; i++){
		step(1);
		stop(1);
		bw=ADRead(0);
		if(bw>500){
			kaeru();
			break;
		}else{
			step(1);
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	step2();

	return 0;
}

