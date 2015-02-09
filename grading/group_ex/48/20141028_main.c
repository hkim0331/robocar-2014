#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void chokushin(int zikan)
{

	  Mtr_Run_lv(10000, -10000, 0, 0, 0, 0); //(左,右，無効,無効,無効,無効)
	  Wait(zikan);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void hidarishin(int kakudo)
{
	int zikan;

	zikan = kakudo *5;

	Mtr_Run_lv(1000, -10000, 0, 0, 0, 0); //(左,右，無効,無効,無効,無効)
	Wait(zikan);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void migishin(int kakudo)
{

	int zikan;

	zikan = kakudo *5;

	  Mtr_Run_lv(10000, -1000, 0, 0, 0, 0); //(左,右，無効,無効,無効,無効)
	  Wait(zikan);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void hidaricho(int kakudo)
{
	int zikan;

	zikan = kakudo *5;

	  Mtr_Run_lv(-10000, -10000, 0, 0, 0, 0); //(左,右，無効,無効,無効,無効)
	  Wait(zikan);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void migicho(int kakudo)
{
	int zikan;

	zikan = kakudo *5;

	  Mtr_Run_lv(10000, 10000, 0, 0, 0, 0); //(左,右，無効,無効,無効,無効)
	  Wait(zikan);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}




int main(void)
{
	  const unsigned short MainCycle = 60;
	  Init(MainCycle);

	  Wait(1000);

	  chokushin(2000);
	  migicho(90);
	  chokushin(2000);
	  migicho(90);
	  chokushin(2000);
	  migicho(90);
	  chokushin(2000);
	  migicho(90);


	  return 0;
}

