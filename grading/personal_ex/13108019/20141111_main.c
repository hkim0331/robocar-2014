#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
# define DO 179
# define RE 160
# define MI 143
# define FA 134
# define SO 120
# define RA 107
# define SI 95
# define DO2 90
# define XX (-1)
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	LED(3);
	int i;
	for (i=0; i<10; i++){
LED(1);
BuzzerSet(95,100);
BuzzerStart();
Wait(500);
BuzzerStop(100);
LED(2);
BuzzerSet(120,100);
BuzzerStart();
Wait(500);
BuzzerStop(100);
	}
	LED(3);
	return 0;
}

