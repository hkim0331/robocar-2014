#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

//音楽のやつ//
#define D   400
#define P   100
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

// 車輪にかけるパワー。
#define L  10000
#define R  10000

//白と黒の中間の数値//
#define M  500

// 進む時間(msec)
#define FW 50


void play(int pitch)
{
	if (pitch==1) {
		BuzzerStop();
		Wait(D+P);
	} else {
		BuzzerSet(pitch, VOL);
		BuzzerStart();
		Wait(D);
		BuzzerStop();
		Wait(P);
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
	LED(0);
	motor(0, 0);
	Wait(500);
}
void forward(void)
{
	LED(3);
	motor(L, R);
	Wait(FW);
}
void turn (short a, short b, int n)
{
	LED(n);
	Mtr_Run_lv(a, -b, 0, 0, 0, 0);
	Wait(50);

}
void slalom(void)
{
	while (1)
		{
			unsigned bw0, bw1;
			bw0=ADRead(0); bw1=ADRead(1);
			if (bw0<M && bw1<M)
			{
				forward();
			}
			else if (bw0>M && bw1<M)
			{
				turn(L, 0, 1);
			}
			else if(bw0<M && bw1>M)
			{
				turn(0, R, 2);
			}
			else if (bw0>M && bw1>M)
			{
				stop(); break;
			}
		}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	slalom();

	kirakira();
	return 0;
}

