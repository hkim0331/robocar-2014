#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void forward(int n )
{
  motor(10000, -10000);
  Wait(n);
  stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(i=0;i=++ )
	return 0;
}

