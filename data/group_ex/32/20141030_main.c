#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define CM 50
#define N 5000

#define DURATION 400
#define DURATION2 200
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


void play(int pitch)
{
	if(pitch == NN){
		BuzzerStop();
		Wait(DURATION + PAUSE);
	}else{
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(DURATION);
		BuzzerStop();
		Wait(PAUSE);
	}
}

void kirakira(void)
{
	int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
			MI,FA,SO,RA,SO,FA,MI,NN,
			DO,NN,DO,NN,DO,NN,DO,XX,
	};
	int i;

	for (i=0; notes[i]!=XX; i++) {
		play(notes[i]);
	}
}
void play2(int pitch)
{
	if(pitch == NN){
		BuzzerStop();
		Wait(DURATION2 + PAUSE);
	}else{
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(DURATION2);
		BuzzerStop();
		Wait(PAUSE);
	}
}

void kirakira2(void)
{
	int notes[]={DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,XX};
	int i;

	for (i=0; notes[i]!=XX; i++) {
		play(notes[i]);
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
	motor(LEFT, RIGHT);
	Wait(CM * s);
	stop(1);
}

void step2(int color)

{int i;
unsigned short bw;
for (i = 0; i < N; i++) {
	step(1);
	stop(1);
	bw=ADRead(0);
	if (bw>500){
		break;
	}else{
		;
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);



	step2(1);


	kirakira();
	kirakira2();
	return 0;
}


}
