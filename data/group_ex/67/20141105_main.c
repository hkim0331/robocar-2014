#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DURATION 500
#define DURATION2 200
#define PARSE 50
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

void play1(int pitch)
{
    if (pitch==NN) {
        BuzzerStop();
        Wait(DURATION);
    } else {
        BuzzerSet(pitch, VOL);
        BuzzerStart();
        Wait(DURATION);
        BuzzerStop();
    }
}

void play2(int pitch)
{
        BuzzerSet(pitch, VOL);
        BuzzerStart();
        Wait(DURATION2);
        BuzzerStop();
        Wait(PARSE);

}

void kaeru(void)
{
    int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
            MI,FA,SO,RA,SO,FA,MI,NN,
            DO,NN,DO,NN,DO,NN,DO,NN,XX};
    int notes2[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};
    int notes3[]={MI,RE,DO,XX};
    int i;

    for (i=0; notes[i]!=XX; i++) {
        play1(notes[i]);
    }
    for (i=0; notes2[i]!=XX; i++) {
            play2(notes2[i]);
        }
    for (i=0; notes3[i]!=XX; i++) {
                play1(notes3[i]);
            }
}




void step(){
	Mtr_Run_lv(10050,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(60);
}



int main(void)
{

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i=0;
	for(i=0; i<10000; i++){
		step();
		Wait(500);
		unsigned short answer;
		answer=ADRead(0);
		if(answer>800)
		{
			break;
		}
		else
		{
			;
		}
	}


    kaeru();


	return 0;
}

