#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define M1 10000
#define M2 10000
#define M3 0
#define M4 0
#define M5 0
#define M6 0


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


int i;
for(i=0;i<4;i++){
	  Mtr_Run_lv(M1, -M2, M3, M4, M5,M6);
	  Wait(1500);
	  Mtr_Run_lv(M1, M2, M3, M4, M5,M6);
	  Wait(1500*2/7);}
Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	return 0;
}

