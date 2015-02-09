#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DO 179
#define MI 142
void play(int pitch)
		{
			BuzzerSet(pitch,100);
			BuzzerStart();
			Wait(1000);
			BuzzerStop();
			Wait(0);
		}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	LED(3);
	Wait(1000);
	int i;
	for(i=0;i<10;i++){
		LED((i%2)+1);
		Wait(1000);
			for(i=0;notes[i] ;i++){
				play(notes[i]);
			}
		}

	}
	LED(0);
	return 0;
}

