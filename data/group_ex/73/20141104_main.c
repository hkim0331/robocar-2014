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
#define ST 0

#define XX (-1)

void play(int pitch)
{

    if (pitch==ST) {
        BuzzerStop();
        Wait(100);
    } else {
        BuzzerSet(pitch, 100);
        BuzzerStart();
        Wait(100);
        BuzzerStop();
        Wait(100);
    }
}


void kaeru (void){
int notes[]={DO,RE,MI,FA,MI,RE,DO,ST,
		MI,FA,SO,RA,SO,FA,MI,ST,
		DO,ST,DO,ST,DO,ST,DO,ST,
		DO,DO,RE,RE,MI,MI,FA,FA,MI,ST,RE,ST,DO,XX};

int i;
for(i=0; notes[i] !=XX; i++){
	play(notes[i]);
}
}




void step (void)
{
	Mtr_Run_lv(11800,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex1 (void)
{
int i;
for(i=0;i<6;i++)
step();
Wait(500);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
	int i;

	for(i=0 ;i<10000 ;i++ ){
		step();
		Wait(100);
		left = ADRead(0);
		if(left>500){
			break;
		}else{
			;
		}

	}
	kaeru();
	return 0;


}


