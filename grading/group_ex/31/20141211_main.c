#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define BUZZERLENGTH2	400
#define BUZZERLENGTH1	100

void buzzer(int i) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(i);
	BuzzerStop();
	Wait(100);
}

void beep100(void) {
	buzzer(BUZZERLENGTH2);
}

void beep10(void) {
	buzzer(BUZZERLENGTH1);
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
  int x[5];
  int i;

  for (i=0;i<5;i++) {
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,5)/5;
}

void color(void) {
  int i,n,t;
  n=average();
  t=0;
  for (i=0; i<n; i+=100) {
	  beep100();
	  t++;
  }
  Wait(500);
  for (i=0; i<(n-t*100); i+=10) {
	  beep10();
  }
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	average();

	color();
}

/*
実験結果

黒　1000
灰　500
緑　300
白  100
赤  100
黄　100
水　100

 */
