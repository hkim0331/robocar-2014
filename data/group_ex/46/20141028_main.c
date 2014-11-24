#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void straight(void)
{
	 Mtr_Run_lv(10500, -10600, 0, 0, 0, 0);
	 Wait(2000);
	 Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	 Wait(500);
}
void turn(void)
{
	 Mtr_Run_lv(-10000, -10000, 0, 0, 0, 0);
	 Wait(833);
	 Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	 Wait(500);
}
int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);
  Wait(2000);
  straight();
  turn();
  straight();
  turn();
  straight();
  turn();
  straight();



  return 0;
}
