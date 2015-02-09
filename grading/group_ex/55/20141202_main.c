#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(500);
}

int sum(int a[], int from, int to) {
  int ret=0;
  int i;

  for (i=from; i<to; i++) {
    ret += a[i];
  }
  return ret;
}

int average(void) {
  int x[10]; //x[0] から始まる５個。配列の最後はx[4]。
  int i;

  for (i=0;i<10;i++) {
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,10)/10;
}

void color(void) {
  int i;
  int n=average();

  for (i=0; i<n; i+=10) {
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

//白90、黄100、赤110、水色120、緑420、灰色600、黒910
