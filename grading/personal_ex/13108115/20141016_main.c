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



void play(int pitch)
{
    if (pitch==NN) {
        BuzzerStop();
        Wait();
    } else {
        BuzzerSet(pitch, VOL);
        BuzzerStart();
        Wait();
        BuzzerStop();
        Wait();
    }
}

void kirakira(void)
{
	int notes[]=(DO,DO,SO,SO,RA,RA,SO,NN
			FA,FA,MI,MI,RE,RE,DO,NN
			SO,SO,FA,FA,MI,MI,RE,NN
			SO,SO,FA,FA,MI,MI,RE,NN
			DO,DO,SO,SO,RA,RA,SO,NN
			FA,FA,MI,MI,RE,RE,DO,XX
			)
	for (i=0; notes[i]!=XX; i++){
			play(notes[i])
		}
}

void kaeru(void)
{
    int notes[]={DO,RE,MI,FA,MI,RE,DO,NN,
            MI,FA,SO,RA,SO,FA,MI,NN,
            DO,NN,DO,NN,DO,NN,DO,NN,
            };
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kirakira();

	kaeru();
	return 0;
}

