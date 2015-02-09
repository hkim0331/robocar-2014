#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT  20000
#define RIGHT 20000
#define FW    64   // (s/cm) //
#define N     100
#define S     1

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



void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
	motor(0, 0);
	Wait(500);
}


void step(double n)
{
	motor(LEFT, RIGHT);
	Wait(FW * n);
	stop();
}

void play(int pitch)
	{
		if (pitch==NN) {
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


void kaeru(void)
	{
		int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
				MI,FA,SO,RA,SO,FA,MI,NN,
				DO,NN,DO,NN,DO,NN,DO,NN,
				DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,XX};
		int i;

		for (i=0; notes[i]!=XX; i++) {
			play(notes[i]);
		}
	}




	int main(void)
	{
		const unsigned short MainCycle = 60;
		Init(MainCycle);

		Wait(1000);

		int i;
        unsigned bw;

		for(i=0; i<N; i++){

			bw=ADRead(0);
			step(S);
			if(bw>500){
				stop();
				kaeru();
			}
		}




	return 0;
	}

