#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define turn90 580

void straight_f(int t){
	Wait(1000);
	  Mtr_Run_lv(-10000, 10000, 0, 0, 0, 0);
	  Wait(t);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	  return 0;
}


void turn_l(void){
	Wait(1000);
	  Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
	  Wait(turn90);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	  return 0;
}

void sc(void){
	int i;
	for( i=0; i<4; i++ ){
		straight_f(1890);
		turn_l();
	}

}

/*
void run(short r_vol, short l_vol, int t){
	Wait(1000);
	Mtr_Run_lv(r_vol, l_vol, 0, 0, 0, 0);//(right,left)
	Wait(t);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	return 0;
}
*/
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(1000);

	sc();
	return 0;
}
