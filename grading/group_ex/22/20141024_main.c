#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int i;

int main(void)
{
i=0;
	for(i=0;i<4;i++);{

  const unsigned short MainCycle = 60;
  Init(MainCycle);
  Wait(2000);
  Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
  Wait(5000);
  Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
  Wait(500);
  Mtr_Run_lv(0, 0, 0, 0, 0,0);
  return 0;}
}
