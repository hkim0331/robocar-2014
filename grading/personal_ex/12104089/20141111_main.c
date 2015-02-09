#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define MI 142
#define XX -1

int notes[]={MI,DO,XX};
	int i;
	for(i=0; notes[i]!=XX; i++){
		play(notes[i]);
	}

void kyukyusya(void){
	int i;
	for(i=0; i<=100; i++){
	BuzzerSet(142,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	BuzzerSet(179,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
}
}

void play(int pitch){
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
}
void start(void){
	LED(3);
	Wait(3000);
}
void led(void){
	int i;
	for(i=0; i<=100; i++){
		LED(i%2+1);
		Wait(100);
	}

	LED(0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    start();
	led();
	kyukyusya();
	return 0;
}

