#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define MI 142

void play(int pitch){
	BuzzerSet(pitch, 200);
		  BuzzerStart();
		  Wait(400);
}
void silen(void){
	int notes[]={DO,MI};
	int i;
		play(notes[i]);
	}
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(400);
	    int i;
	    for (i=0; i<100; i++) {
	        LED((i%2)+1);
	        Wait(400);
	        silen;
	    }

    LED(0);
    return 0;
}
