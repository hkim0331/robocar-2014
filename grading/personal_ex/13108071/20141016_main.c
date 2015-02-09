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
#define NN    0

#define XX    (-1)



void play(int pitch){
	if(pitch==NN){
		BuzzerStop();
		Wait(500);
	}else{
		BuzzerSet(pitch, 100);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
		Wait(100);
	}
}

void music(int line[])
{
    int i;

    for (i=0; line[i]!=XX; i++) {
        play(line[i]);
    }
}

void kaeru(void)
{
	int line[]={DO,RE,MI,FA,MI,RE,DO,NN,
			MI,FA,SO,RA,SO,FA,MI,NN,
			DO,NN,DO,NN,DO,NN,DO,NN,
			DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,XX};

	music(line);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kaeru();

	return 0;
}

