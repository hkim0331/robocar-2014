#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define m1 10000


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
void go(int time){
	Mtr_Run_lv(m1, -m1, 0, 0, 0, 0);
	Wait(time);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void right(int time ){
	Mtr_Run_lv(m1, m1, 0, 0, 0, 0);
		Wait(time);
		Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}
int i;
	for (i=0; i<4; i++){
go(2000);
right(550);

	}
	return 0;
}













