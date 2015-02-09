#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10

void turn_on(int length) {
  LED(3);
  Wait(length);
  LED(0);
  Wait(100);
}
//LEDで明るさを判別

int average(int a[], int start, int end) {
	int ret=0;
	  int i;

	  for (i=start; i<end; i++) {
	    ret += a[i];
  }
  return ret/(end-start);
}


int color(int n) {
  int c[n];
  int i;

  for (i=0; i<n; i++) {

	  c[i] = ADRead(0);
	  Wait(100);
  }
  return average(c,0,n);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int c;
	int h; //100
	int d; //10

	while(1){
		Wait(1000);
		c = color(N);
		h = c / 100; //cを100で割る
		d = c % 10; //cを10で割ったあまり
		while (h>0){
			turn_on(800);
			h--;
        	}
		while(d>0){
			turn_on(400);
			d--;
		}
	}
    return 0;
}
