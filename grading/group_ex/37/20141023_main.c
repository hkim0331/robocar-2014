#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	  int i;
	const unsigned short MainCycle = 60;
	Init(MainCycle);
      Wait(1000);
  for(i=0;i<4;i++)   {
	  Mtr_Run_lv(10000, -9500, 0, 0, 0, 0);
      Wait(2000);
      Mtr_Run_lv(0, 0, 0, 0, 0, 0);
      Wait(500);
	Mtr_Run_lv(-10000, -10000, 0, 0, 0, 0);
	  Wait(620);
  }
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	  return 0;
	}


