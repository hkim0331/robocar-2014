#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define N 1;



int main(void)
{
Wait(1000);
void forward(int n){
	motor(500,500);
	Wait(1000);
	stop(1000);
}

	Init(MainCycle);



	return 0;
}

