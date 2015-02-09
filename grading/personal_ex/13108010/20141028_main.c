#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int a,int b,int c,int d){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(c);
	Mtr_Run_lv(a, b, 0, 0, 0, 0);
	  Wait(d);
	  Mtr_Rum_lv(0,0,0,0,0,0);
}




int main(void)
{

	  play(10000,-10000,0,50);
	return 0;}

