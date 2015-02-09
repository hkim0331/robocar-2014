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
#define XX    0
#define NN		1

void play(int pitch)
{
	if(pitch == 1){
	BuzzerStop();
	Wait(DURATION + PAUSE);
}else{

	BuzzerSet(pitch, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
}
}
void play2(int pitch)
{
	if(pitch == 1){
	BuzzerStop();
	Wait(DURATION + PAUSE);
}else{

	BuzzerSet(pitch, 100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}
}
void kirakira(void)
{
	int s[]={DO,RE,MI,FA,MI,RE,DO,NN,MI,FA,SO,RA,SO,FA,MI,NN,DO,NN,DO,NN,DO,NN,DO,NN,XX};
	int t[]={DO,DO,RE,RE,MI,MI,FA,FA,MI,NN,RE,NN,DO,XX};
	int i;

	for(i=0;s[i]!=XX;i++)
	{
		play(s[i]);

	}
	for(i=0;t[i]!=XX;i++)
	{
		play2(t[i]);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	kirakira();

	return 0;

}

