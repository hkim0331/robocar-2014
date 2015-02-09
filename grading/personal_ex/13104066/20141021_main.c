#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch){
	BuzzerSet(pitch,100);
    BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(400);
}
void DO(void){
	play(179);
}

void SO(void){
	play(120);
}

void RA(void){
	play(107);
}

void FA(void){
	play(134);
}


int main(void)
{

	const unsigned short MainCycle = 60;
	Init(MainCycle);

    DO();
	DO();
	SO();
	SO();
    RA();
	RA();
	SO();

	FA();
	FA();

	for(i=0;i<2;i++){
			BuzzerSet(134,100);
			BuzzerStart();
			Wait(700);
			BuzzerStop();
			Wait(700);
		}
	for(i=0;i<2;i++){
			BuzzerSet(142,100);
			BuzzerStart();
			Wait(700);
			BuzzerStop();
			Wait(700);
		}
	for(i=0;i<2;i++){
			BuzzerSet(160,100);
			BuzzerStart();
			Wait(700);
			BuzzerStop();
			Wait(700);
		}
	        BuzzerSet(179,100);
			BuzzerStart();
			Wait(700);
			BuzzerStop();
			Wait(700);
		for(n=0;n<2;n++){
			for(i=0;i<=1;i++){
					BuzzerSet(120,100);
					BuzzerStart();
					Wait(700);
					BuzzerStop();
					Wait(700);
				}
			for(i=0;i<=1;i++){
								BuzzerSet(134,100);
								BuzzerStart();
								Wait(700);
								BuzzerStop();
								Wait(700);
							}
			for(i=0;i<=1;i++){
								BuzzerSet(142,100);
								BuzzerStart();
								Wait(700);
								BuzzerStop();
								Wait(700);
							}

								BuzzerSet(160,100);
								BuzzerStart();
								Wait(700);
								BuzzerStop();
								Wait(700);
}
}
	return 0;
}

