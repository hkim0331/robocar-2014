#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch, int vol, int duration, int pause)
{
    BuzzerSet(pitch, vol);
    BuzzerStart();
    Wait(duration);
    BuzzerStop();
    Wait(pause);
}
void SO(void)
{
    play(120,100,400,100);
void RO(void)
    {
        play(107,100,400,100);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	LED(3);
	Wait(1000);
	int i;
	for(i=0; i<10;i++){
	 if((i%2+1));{
		 SO();
		 Wait(1000);
		 RO();
	 }

	 Wait(100);

	}
	LED(0);

	return 0;
}


