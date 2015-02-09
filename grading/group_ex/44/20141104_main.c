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
#define NN 0

void step(int time){
	Mtr_Run_lv(23000,-20000,0,0,0,0);
		Wait(time);
		Mtr_Run_lv(0,0,0,0,0,0);
}

void halt(int time){
	Wait(time);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void play(int pitch)
{
  if(pitch==NN)
  {
	BuzzerStop();
    Wait(400);
  }
  else
  {
  BuzzerSet(pitch, 100);
  BuzzerStart();
  Wait(400);
  BuzzerStop();
  Wait(100);
  }
}

void kaeru(void)
{
  int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,RA,SO,FA,MI,NN,DO,NN,DO,NN,DO,NN,DO,
		  NN,DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,NN,XX};
  int i;
  for(i=0;notes[i] != XX; i++)
  {
    play(notes[i]);

  }
}


int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    unsigned short left;

	/*int i;
	for(i=0;i<6;i++){
	  step(27);
      halt(500);
	}*/

    for(;;){
    	step(77);
    	halt(500);
    	left = ADRead(0);
    	if(left>=750 && left<=1023){
    	  break;
    	}

    }

    kaeru();

	return 0;
}

