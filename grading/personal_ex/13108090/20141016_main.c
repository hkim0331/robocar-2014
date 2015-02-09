#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define NN    1
#define XX    0

void play(int pitch){
	if(pitch==NN){
		BuzzerStop();
		Wait(400+100);
	} else{
	BuzzerSet(pitch, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
	}
}

void kirakira(void){
	int s[]={DO,RE,MI,FA,MI,RE,DO,XX};
	int i;

	for (i=0; s[i]!=XX;i++){
		play(s[i]);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kirakira();

	return 0;
}

