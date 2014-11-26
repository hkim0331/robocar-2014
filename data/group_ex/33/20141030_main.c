#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define FW 10
#define EDGE 8
#define N 5000


void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}


void stop(void)
{
  motor(0, 0);
}

void forward(int n)
{
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}

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

void play(int pitch)
{
	if (pitch == NN){
		BuzzerStop();
		Wait(DURATION + PAUSE);
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

	for(i=0; notes[i]!=XX;i++){
		play(notes[i]);
	}
}

void kaeru(void)
{
	int s[]={DO,RE,MI,FA,MI,RE,DO,NN,
			MI,FA,SO,RA,SO,FA,MI,NN,
			DO,NN,DO,NN,DO,NN,DO,NN,XX,
			DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,XX};
	music(s);




}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	unsigned short bw;

	Wait(1000);
	int i;
	for (i = 0; i < N; i++) {
		forward(EDGE);
        Wait(500);
        bw = ADRead(0);
        if(bw > 500){
        	break;
        }else{
        	;
        }

	}
	kaeru();


	return 0;
}

