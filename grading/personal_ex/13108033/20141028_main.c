#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void ex1(void){
Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);
Mtr_Run_lv(10000,-10000,0,0,0,0);
Wait(100);
Mtr_Run_lv(0,0,0,0,0,0);}

void ex2(void){



}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(1000);
	Mtr_Run_lv(0,0,0,0,0,0);

return 0;
}

