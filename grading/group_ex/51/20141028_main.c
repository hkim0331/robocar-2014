#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void str(int dis)
{
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);//13cm/s
	  Wait(1000/13*dis);
}

void left(void)
{
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);//13cm/s
		  Wait(500);
}

void circle(void)
{
str(30);
left();
str(30);
left();
str(30);
left();
str(30);
left();
}


int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  circle();

  return 0;
}
