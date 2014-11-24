#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
  Wait(1000);

  void play1 (void){
  Mtr_Run_lv(13500, -10000, 0, 0, 0, 0);
  Wait(3333);
  }

  void play2 (void){
  Mtr_Run_lv(13500, 0, 0, 0, 0, 0);
  Wait(700);
  }
  int i;
  for(i=0;i<4;i++){
	play1();
	play2();
  }
  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
  Wait(1000);

  return 0;
}
