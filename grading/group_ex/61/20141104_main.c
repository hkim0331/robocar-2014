#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
int i;
unsigned short left;

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define DO2 90
#define XX (-1)
#define MU 0
void play(int pitch)
{
	if(pitch == MU)
	{BuzzerStop();
	Wait(400);
	}else{
	BuzzerSet(pitch, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);}

}
void play2(int bitch){
	BuzzerSet(bitch, 100);
	BuzzerStart();
	Wait(800);
	BuzzerStop();
	Wait(100);


}
void play3(int kitch){
	BuzzerSet(kitch, 100);
	BuzzerStart();
	Wait(125);
	BuzzerStop();
	Wait(100);

}
void play4(int titch){

	if(titch == MU)
	{BuzzerStop();
	Wait(400);
	} else {
	BuzzerSet(titch, 100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
	}
}

void kaeru(void){
	int notes[]={DO,RE,MI,FA,MI,RE,DO,MU,MI,FA,SO,RA,SO,FA,MI,MU,XX};
	int notes2[]={DO,DO,DO,DO,XX};
	int notes3[]={DO,DO,RE,RE,MI,MI,FA,FA,XX};
	int notes4[]={MI,RE,DO,MU,XX};

	for(i=0;notes[i]!=XX;i++){
		play(notes[i]);
	}
	for(i=0;notes2[i]!=XX;i++){
		play2(notes2[i]);

	}
	for(i=0;notes3[i]!=XX;i++){
		play3(notes3[i]);

	}

	for(i=0;notes4[i]!=XX;i++){
		play4(notes4[i]);

	}

}





void step(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(120);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex1(void)
{
	for(i=0;i<6;i++){
		step();
		Wait(500);
	}
}

void gr1(void){
	for( ; ; ){
		step();
		Wait(500);
		left = ADRead(0);
	if(700<left){
		break;
		} else {
	;}

	}

	kaeru();

}

int main(void)
{

	const unsigned short MainCycle = 60;
	Init(MainCycle);

  gr1();

	return 0;
}

