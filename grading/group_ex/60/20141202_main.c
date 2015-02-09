#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(150);
}

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
  }
  return sum(x,0,n)/n;
}

void color(void) {
  int i;
  int n=average(1000);

  for (i=0; i<n; i+=5) {
    beep();
  }
}


int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}


//黒：870
//グレー：310
//緑：70
//青：50
//赤50
//黄：50
//白：40
