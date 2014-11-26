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


void robocarmtr(int hidari,int migi,int zikan)
{
	  Mtr_Run_lv(hidari,migi, 0, 0, 0, 0); //(左,右，無効,無効,無効,無効)
	  Wait(zikan);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}


void chokushin(int zikan)
{
	robocarmtr(10000,-10000,zikan)	;
}

void hidarishin(int kakudo)
{
	int zikan;

	zikan = kakudo *10;

	robocarmtr(1000,-10000,zikan)	;
}

void migishin(int kakudo)
{

	int zikan;

	zikan = kakudo *10;

	robocarmtr(10000,-1000,zikan)	;
}

void hidaricho(int kakudo)
{
	int zikan;

	zikan = kakudo *5;

	robocarmtr(10000,10000,zikan)	;
}

void migicho(int kakudo)
{
	int zikan;

	zikan = kakudo *5;

	robocarmtr(-10000,-10000,zikan)	;
}



void play(int pitch,int nagasa)
{
	int saiseinagasa;

	saiseinagasa = nagasa * 300  - 50;


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
	Wait(50);
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

void step(void){

	chokushin(100);
	Wait(1000);

	}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int j=1;
	unsigned short migi,hidari;

	Wait(2000);

	while(j){

		migi = ADRead(0);
		hidari = ADRead(1);

		step();


		if (migi>512 && hidari >512){
			j=0;
			}else{
			;
			}

		}


	kaerunouta();

	return 0;
}

