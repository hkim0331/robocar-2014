#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void z(void)
{
	Mtr_Run_lv(10000, -9000, 0, 0, 0, 0);
	Wait(2300);
}

void k(void)
{
	Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
	Wait(800);
}

int main(void)
{
  int i=0;

  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(2000);

  while(i<4)
  {
	  z();
	  k();
	  i++;
  }

  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

  return 0;
}
