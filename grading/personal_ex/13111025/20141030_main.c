#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define EDGE 5

#define FW 40

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void forward(int m)
{
  motor(LEFT, RIGHT);
  Wait(FW * m);
  stop();
  Wait(1000);
}


unsigned short ADRead (unsigned char n);

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	  Wait(1000);
	  int i;
	  for (i = 0; i < 100000 i++) {
	    forward(EDGE);
	  }

	return 0;
}

