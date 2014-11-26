#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DURATION 400
#define PAUSE 100
#define VOL 20

#define DO 179
#define DO2 180
#define DO3 178
#define RE 160
#define RE2 159
#define MI 142
#define MI2 141
#define FA 134
#define FA2 133
#define SO 120
#define RA 107
#define SI 95
#define NN 0
#define XX (-1)

void play(int pitch){
	if (pitch == NN){
		BuzzerStop();
		Wait(DURATION+PAUSE);
	}

	else if(pitch == DO2){
			BuzzerSet(pitch,VOL);
			BuzzerStart();
			Wait(800);
			BuzzerStop();
					Wait(250);
		}
	else if(pitch == DO3){
			BuzzerSet(pitch,VOL);
			BuzzerStart();
			Wait(200);
			BuzzerStop();
					Wait(50);
		}
	else if(pitch == RE2){
			BuzzerSet(pitch,VOL);
			BuzzerStart();
			Wait(200);
			BuzzerStop();
					Wait(50);
		}
	else if(pitch == MI2){
			BuzzerSet(pitch,VOL);
			BuzzerStart();
			Wait(200);
			BuzzerStop();
					Wait(50);
		}
	else if(pitch == FA2){
			BuzzerSet(pitch,VOL);
			BuzzerStart();
			Wait(200);
			BuzzerStop();
					Wait(50);
		}
	else {
		BuzzerSet(pitch,VOL);
		BuzzerStart();
		Wait(DURATION);
		BuzzerStop();
		Wait(PAUSE);
	}
}
void music(int notes[]){
	int i;
for(i=0;notes[i]!=XX;i++)
{	play (notes[i]);}
}

void kaeru(void){
		int notes1[]={DO,RE,MI,FA,MI,RE,DO,NN,
					MI,FA,SO,RA,SO,FA,MI,NN,XX};

			int notes2[]={DO2,DO2,DO2,DO2,XX};

		int notes3[]={DO3,DO3,RE2,RE2,MI2,MI2,FA2,FA2,XX};

		int notes4[]={MI,RE,DO,XX};

		music(notes1);
		music(notes2);
		music(notes3);
		music(notes4);


}


void step(void){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(5000/60);
	Mtr_Run_lv(0,0,0,0,0,0);
}
void stop(void){
	Mtr_Run_lv(0,0,0,0,0,0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

unsigned short left;
	for( ; ; ){
	step();
	Wait(500);
	left=ADRead(0);

if(left>500){
	stop();
	kaeru();
}
else{
	;
}

	}
	return 0;
}

