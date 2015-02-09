#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void go(int rpwr,int wait)
{


	  Mtr_Run_lv(rpwr, -18000, 0, 0, 0, 0);
	  Wait(wait);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);



}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	go(20000,1000);
    go(0,400);
	go(20000,1000);
    go(0,400);
    go(20000,1000);
    go(0,400);
    go(20000,1000);

	return 0;
}

