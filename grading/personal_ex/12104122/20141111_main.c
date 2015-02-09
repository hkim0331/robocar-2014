#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define RE 160
#define MI 142
#define FA 134
#define SO 120
#define RA 107
#define SI 95
#define DO2 90
#define XX -1

void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(300);
	BuzzerStop();
	Wait(100);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);

	int i;
	for (i=0; i<100; i++){
		LED((i%2)+1);
		if ((i%2)+1=1){
			play(MI);
		}
		else{
			play(DO);
		}
		Wait(1000);
	}

	return 0;
}

