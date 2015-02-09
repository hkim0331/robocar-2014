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

void light(n){
	LED(n);
	Wait(100);
	LED(0);
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

int average(n) {
 int x[n];
 int i;

 for(i=0; i<n; i++){
	 x[i] = ADRead(0);
	 Wait(100);
 }
 return sum(x,0,n)/n;
}

void color(void) {
  int i;
  int n=average(5);

  for (i=0; i<n; i+=100) {
      light(2);
    }

  for (i=0; i<n; i+=10) {
      light(1);
    }

  for (i=0; i<n; i+=1) {
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

//グレー、緑、青、黄、赤
