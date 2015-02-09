#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch){
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(200);
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

void RE(void){
	play(160);
}

void MI(void){
	play(142);
}

void SI(void){
	play(95);
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
	Wait(200);
	FA();
	FA();
	MI();
	MI();
	RE();
	RE();
	DO();
	return 0;
}

