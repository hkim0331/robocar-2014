#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define MI 142
#define DO 179

void play(int pitch)
{
	BuzzerSet(pitch, 100);
    BuzzerStart();
    Wait(400);
    BuzzerStop();
    Wait(100);
}
void music(int notes[])
{
    int i;

    int notes[]={MI,DO};
    for(i=0;notes[i]!=XX;i++)
    {
    	play(notes[i]);
    }
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    LED(3);
    Wait(1000);
    int i;
    for (i=0; i<100; i++) {
       LED((i%2)+1);
       music();
       Wait(100);
    }
    LED(0);

	return 0;
}

