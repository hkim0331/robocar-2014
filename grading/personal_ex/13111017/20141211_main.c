#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

int average() {
  int x[5];
  int i;

  for (i=0;i<5;i++) {
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,5)/5;
}


void color(void) {
  int i;
  int n = average();

  for (i=0; i<5; i+100) {
    beep();
  }
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	color();

	return 0;
}

