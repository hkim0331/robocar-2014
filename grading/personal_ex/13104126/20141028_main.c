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

	  Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	  Wait(80);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);    // エラー
	  Wait(1000);

	  Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	  Wait(800);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);    // エラー
	  Wait(1000);

	  Mtr_Run_lv(-10000, 10000, 0, 0, 0, 0);
	  Wait(400);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);    // エラー
	  Wait(1000);

	  Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
	  Wait(1200);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);    // エラー
	  Wait(1000);

	  Mtr_Run_lv(0, 10000, 0, 0, 0, 0);
	  Wait(4800);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);    // エラー
	  Wait(1000);


	  return 0;
}

