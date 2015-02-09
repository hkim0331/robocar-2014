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
#define XX    0



void play(int pitch,int t,int w){

	if(pitch==0){
		Wait(t+w);
	}
	else{
	 BuzzerSet(pitch,100);
	 BuzzerStart();
	 Wait(t);
	 BuzzerStop();
	 Wait(w);
	}

}

void doremi(){

	play(DO,400,100);
	play(RE,400,100);
	play(MI,400,100);
	play(FA,400,100);
	play(MI,400,100);
	play(RE,400,100);
	play(DO,400,100);
	play(XX,400,100);

	play(MI,400,100);
	play(FA,400,100);
	play(SO,400,100);
	play(RA,400,100);
	play(SO,400,100);
	play(FA,400,100);
	play(MI,400,100);
	play(XX,400,100);

	play(DO,400,100);
	play(XX,400,100);
	play(DO,400,100);
	play(XX,400,100);
	play(DO,400,100);
	play(XX,400,100);
	play(DO,400,100);
	play(XX,400,100);

	play(DO,200,50);
	play(DO,200,50);
	play(RE,200,50);
	play(RE,200,50);
	play(MI,200,50);
	play(MI,200,50);
	play(FA,200,50);
	play(FA,200,50);
	play(MI,400,100);
	play(RE,400,100);
	play(DO,400,100);
	play(XX,400,100);

}

void Run(int Right, int Left, int time){

	Mtr_Run_lv(Right, Left, 0, 0, 0, 0); //モーターを最大6個載せられるから６つ
	Wait(time);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short color0,color1;
	int i;

	for(i=0;i<1000;i++){
		color0 = ADRead(0);
		color1 = ADRead(1);
		if(color0 > 500 || color1 >500){
			doremi();
		}else{
			Run(10000,-10000,50);
			Wait(1000);
		}
	}
	return 0;
}
