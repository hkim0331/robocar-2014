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

#define X 0
#define XX -1

void play(int pitch){
	BuzzerSet(pitch,100);
			BuzzerStart();
			Wait(400);
			BuzzerStop();
			Wait(100);
}
void play2(int pitch){
    BuzzerSet(pitch,100);
			BuzzerStart();
			Wait(200);
			BuzzerStop();
			Wait(50);
}

void kaeru(void){
	int notes[]={DO,RE,MI,FA,MI,RE,DO,X,MI,FA,SO,RA,SO,FA,MI,X,DO,X,DO,X,DO,X,DO,X,XX};
	int i;
	for(i=0;notes[i] !=XX;i++){
		if(notes[i]==X){
			BuzzerStop;
			Wait (500);
		}else{
		play(notes[i]);}
	}
	int notes2[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};
	int u;
	for(u=0;notes2[u] !=XX;u++){
		play2(notes2[u]);
	}
	int notes3[]={MI,RE,DO,XX};
	for(i=0;notes3[i] !=XX;i++){
		play(notes3[i]);
	}
}

void step(){
	Mtr_Run_lv(10030,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
	for(;;){
	    step();
	    Wait(500);
	    left = ADRead(0);
	    if(left>500)
	    	break;
	}
	kaeru();

	return 0;
}

