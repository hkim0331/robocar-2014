#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO (120)
#define SI (95)
#define XX (-1)

void play (int pitch)
{
	BuzzerSet(pitch,100);
		BuzzerStart();
		Wait(500);
		BuzzerStop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	
void kaeru(void);
{
	int notes[]={SI,SO,XX};
	int i;
	for (i=0; notes[i] !=XX;i++);
	{
		play(notes[i]);
	}
	}

	LED(0);
	int i;
	for (i=0;i<10;i++) {
		LED(i%2 +1);
		Wait(500);
	}
	LED(0);

	return 0;
}

