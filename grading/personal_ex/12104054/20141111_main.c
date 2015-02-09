#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DO 179
#define MI 142
#define XX -1

void play(int pitch){
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
}
void pi-po(void){
	int notes[]={DO,DO,SO,SO,RA,RA,SO,XX};
	int i;
	for(i=0; notes[i]!=XX; i++);
	{
		play(notes[i]);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(3000);
	int i;
	for(i=0;i<=100;i++){
		LED(i%2+1);
		Wait(100);
	}
	LED(0);

	return 0;
}

