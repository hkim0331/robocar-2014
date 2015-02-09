#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int sum(int a[], int from, int to) {
  int ret=0;
  int i;

  for (i=from; i<to; i++) {
    ret += a[i];
  }
  return ret;
}

int average(int n) {
  int x[n];
  int i;

  for (i=0;i<n;i++) {
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,n)/n;
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);



	return 0;
}

