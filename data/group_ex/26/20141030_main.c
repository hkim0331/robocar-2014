/*
	 ============================================================================
	 Name        : motor/src/main.c
	 Author      : Nomi Nakamura
	 Version     : 1.0
	 Copyright   : yasuyo
	 Description : yumiko
	 ============================================================================
 */
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



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



// 車輪にかけるパワー。ロボカーによって変わる。
// 実験で求めるべし。
#define LEFT   10000
#define RIGHT  10000

// 何回進むか？
#define N 50000

// 1cm 進む時間(msec)
// これらの値は実験で求める。ロボカーによって異なる。
#define FW 37


void play(int pitch)
{
	if (pitch==1) {
		BuzzerStop();
		Wait(DURATION+PAUSE);
	} else {
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(DURATION);
		BuzzerStop();
		Wait(PAUSE);
	}
}

void music(int notes[])
{
	int i;

	for (i=0; notes[i]!=XX; i++) {
		play(notes[i]);
		};


}

void kirakira(void)
{

	int notes[]={DO,DO,SO,SO,RA,RA,SO,NN,
				 FA,FA,MI,MI,RE,RE,DO,NN,
				 SO,SO,FA,FA,MI,MI,RE,NN,
				 SO,SO,FA,FA,MI,MI,RE,NN,
				 DO,DO,SO,SO,RA,RA,SO,NN,
				 FA,FA,MI,MI,RE,RE,DO,XX,};

	music(notes);

}



void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
	motor(0, 0);
	Wait(500);
}

void forward(void)
{
	motor(LEFT, RIGHT);
	Wait(FW);
	stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	int i;
	unsigned bw;

	for (i = 0; i < N; i++)
	{
		forward();
		bw = ADRead(0);

		if(bw >500)
			{
				break;
			} else{
				;
			}
	}

	kirakira();

	return 0;
}
