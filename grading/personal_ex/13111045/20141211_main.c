#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#include N 10

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

int average(int a[], int from ,int to) {
  int ret=0;
  int i;

  for (i=from;i<to;i++) {
  ret +=a[i];


  }
  return ret/(to-from);
}


 int color(int n) {
	int c[n];
    int i;

  for (i=0; i<n; i++) {
	  c[i]= ADRead(0);
	  Wait(100);
    beep();
  }
  return average(c,0,n);

}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);



	return 0;
}

