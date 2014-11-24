#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void turn()
{
	  Mtr_Run_lv(0,-10000, 0, 0, 0, 0);//90度右回り
	  Wait(1000);
}

void run()
{
	  Mtr_Run_lv(10000, -10500, 0, 0, 0, 0);//30cm前進
	  Wait(2500);
}

void wait()
{
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0); //1秒停止
	  Wait(1000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	  Init(MainCycle);

      wait();

      run();
      turn();

      run();
      turn();

      run();
      turn();

      run();
      wait();

	  return 0;
}

