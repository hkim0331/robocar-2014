#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int i;

void run()
{
	Mtr_Run_lv(6000, 6000, 0, 0, 0, 0);
	Wait(730);
}

void turn()
{
	Mtr_Run_lv(9650, -10000, 0, 0, 0, 0);
	Wait(2200);
}

void stop()
{
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(500);
}

int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  Wait(1000);

  for (i=0; i<=3; i++){
	  run();
	  stop();
	  turn();
	  stop();
  	  }

  Mtr_Run_lv(0, 0, 0, 0, 0, 0);    // エラー

  return 0;
}
