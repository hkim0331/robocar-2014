#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

int average(int a[], int from, int to){
	int ret=0;
	int i;

	for (i=from; i<to; i++){
		ret += a[i];
	}
	return ret/(to-from);
}

int color(int n){
	int c[n];
	int i;

	for (i=0; i<n; i++){
		c[i] = ADRead(0);
		Wait(100);
	}
	return average(c,0,n);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(100);
	LED(3);
	Wait(100);
    int i;
    int m;
    while(1){
    	m = color(10);
    	int c = m/100;
    	int h = (m%100)/10;
    while(c>0){
    	for (i=0; i<c; i++){
    		beep();
    	    LED(2);
    	    Wait(150);
    	}
    	Wait(100);
    while(h>0){
    	for (i=0; i<h; i++){
    		beep();
    		LED(1);
    		Wait(150);
    	}
    }
    }

    }
	return 0;
}

