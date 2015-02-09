#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  9000

#define FW
#define TN


void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void forward(int n)
{
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	  for (i = 0; i < N; i++) {
	    forward(EDGE);

	return 0;
}

