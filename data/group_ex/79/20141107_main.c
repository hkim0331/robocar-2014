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
#define NN    0

#define XX    (-1)

void play(int pitch)
{
	static int a=0;

    if (pitch==NN) {
        BuzzerStop();
        Wait(DURATION+PAUSE);
    } else {
        BuzzerSet(pitch, VOL);
        BuzzerStart();
        if(a<=17 || 26<=a){
        	Wait(DURATION);
        	BuzzerStop();
        	Wait(PAUSE);
        }
        else if(17<a && a<26){
        	 Wait(DURATION/2);
        	 BuzzerStop();
        	 Wait(PAUSE/2);
        }

       a++;
    }
}

void music(int notes[])
{
    int i;

    for (i=0; notes[i]!=XX; i++) {
        play(notes[i]);
    }
}



void kaeru(void)
{
    int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
            MI,FA,SO,RA,SO,FA,MI,NN,
            DO,NN,DO,NN,DO,NN,DO,NN,
            DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,NN,XX};

  music(notes);
}
void step(void){
		Mtr_Run_lv(-10000,10000,0,0,0,0);
		Wait(280);
		Mtr_Run_lv(0,0,0,0,0,0);
        Wait(500);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    unsigned short left;


	do{
		step();
     left=ADRead(0);
	}while(left<800);

	if(left>=800){
		kaeru();
	}else{
		;
	}


	return 0;
}

