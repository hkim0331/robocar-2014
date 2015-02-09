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
#define hDO 90
#define YASUMI 999
#define XX -1



void play(int pitch,int nagasa)
{
	int saiseinagasa;

	saiseinagasa = nagasa * 500  - 100;


	if(pitch != YASUMI){
		BuzzerSet(pitch, 100);
		BuzzerStart();
		Wait(saiseinagasa);
		}
	else{
		BuzzerStop();
		Wait(saiseinagasa);
		}

	BuzzerStop();
	Wait(100);
}



void kaerunouta(void)
{
	int notes[]=	{DO,RE,MI,FA,MI,RE,DO,YASUMI
					,MI,FA,SO,RA,SO,FA,MI,YASUMI
					,DO,DO,DO,DO
					,DO,DO,RE,RE,MI,MI,FA,FA,MI,RE,DO,YASUMI
					,XX};
	int nagasa[]=	{2,2,2,2,2,2,2,2
					,2,2,2,2,2,2,2,2
					,4,4,4,4
					,1,1,1,1,1,1,1,1,2,2,2,2
					,1};
	int i;

	for(i=0;notes[i] != XX;i++){
		play(notes[i],nagasa[i]);
		}


	}


int main(void)
{
	int migi,hidari;

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	while(1){

		migi = ADRead(0);
		hidari = ADRead(1);



		}


	kaerunouta();
	return 0;
}

