#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int pitch)
{
	if(pitch==1){
		BuzzerSet(142, 100);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
	}
	if(pitch==2){
		BuzzerSet(179, 100);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
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
        play((i%2)+1);
        Wait(400);
         }
    LED(0);
    return 0;
}
