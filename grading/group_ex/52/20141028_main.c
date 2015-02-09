#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	  Wait(2000);
	  Mtr_Run_lv(10030, -10000, 0, 0, 0, 0);
	  Wait(2300);
	  Mtr_Run_lv(0,0, 0, 0, 0, 0);
	  Wait(1);
	  Mtr_Run_lv(-10050,-10000,0,0,0,0);
	  Wait(500);
	  Mtr_Run_lv(0,0,0,0,0,0);
	  Wait(1);
	  Mtr_Run_lv(10030,-10000,0,0,0,0);
	  Wait(2300);
	  Mtr_Run_lv(0,0,0,0,0,0);
	  Wait(0);
	  Mtr_Run_lv(-10050,-10000,0,0,0,0);
	  Wait(500);
	  Mtr_Run_lv(10030,-10000,0,0,0,0);
	  Wait(2300);
	  Mtr_Run_lv(0,0,0,0,0,0);
	  Wait(1);
	  Mtr_Run_lv(-10050,-10000,0,0,0,0);
	  Wait(500);
	  Mtr_Run_lv(0,0,0,0,0,0);
	  Wait(1);
	  Mtr_Run_lv(10030,-10000,0,0,0,0);
	  Wait(2300);
	  Mtr_Run_lv(0,0,0,0,0,0);
	  Wait(2000);



	return 0;
}

