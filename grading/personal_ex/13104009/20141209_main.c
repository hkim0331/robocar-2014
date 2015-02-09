#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define Black 600
#define hai 200
#define l 10030
#define r 10000

void motor(int Left, int right){
	Mtr_Run_lv(l, r, 0,0,0,0);
}
void stop(void){
	motor(0,0);
}
void forward(int)
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

