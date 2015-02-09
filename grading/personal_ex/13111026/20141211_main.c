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

int sum(int a[], int from, int to) {
  int ret=0;
  int i;

  for (i=from; i<to; i++) {
    ret += a[i];
  }
  return ret;
}

int average(void) {
  int x[5]; //x[0] から始まる５個。配列の最後はx[4]。
  int i;

  for (i=0;i<5;i++) {
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,5)/5;
}

void color(void) {
  int i;
  int n=average();

  for (i=0; i<n; i++) {
    beep();
  }
}
