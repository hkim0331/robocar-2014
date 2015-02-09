#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Mtr_Run_lv(short m1, short m2, short m3, short m4, short m5, short m6)
{

}


int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);


  Wait(2000);
  Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
  Wait(66);
  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

  Wait(2000);

  return 0;
}
