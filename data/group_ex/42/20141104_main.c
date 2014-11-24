#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define DO2 90
#define XX -1


void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
}


unsigned short left;
unsigned short right;

void go(void){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
}

void stop(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void step(void){
	go();
	Wait(90);
	stop();
}

void kaeru(void){
	int notes[]={DO,RE,MI,FA,MI,RE,DO,XX};
	int i;
	for(i=0; notes[i]!=XX; i++){
		play(notes[i]);
	}
}

void kaeru2(void){
	int notes[]={SI,RA,SO,RA,SO,FA,MI,XX};
	int i;
	for(i=0; notes[i]!=XX; i++){
		play(notes[i]);
	}
}

void KAERU(void){
	kaeru();
	Wait(500);
	kaeru2();
}

void run(void){
	Wait(1000);
	for (;;) {
	   if(left < 500){
		   step();
	    }else{
	       KAERU();
	       break;
	    }
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


    run();


	return 0;
}
