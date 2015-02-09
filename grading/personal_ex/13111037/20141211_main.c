#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep() {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}
int average(int n) {
  int x[n];
  int i;

  for (i=0;i<n;i++) {}
    x[i] = ADRead(0);
    Wait(100);
    x[]
  }
  return ()/n;
}




void color(void) {
  int i;
  int n=average();

  for (i=0; i<n; i++) {
    beep();
  }
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

