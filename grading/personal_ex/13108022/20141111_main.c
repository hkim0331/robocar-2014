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
#define NN 0
#define XX (-1)
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i;
	LED(3);
	Wait(1000);
	for(i=0; i<100; i++){
		LED((i%2)+1);
		Wait(100);
	if((i%2)+1){BuzzerSet(95, 100);
	  BuzzerStart();
	  Wait(70);
	  BuzzerStop();
	} else {BuzzerSet(120, 100);
	  BuzzerStart();
	  Wait(70);
	  BuzzerStop();
	}
	}
	LED(0);
    return 0;
}

