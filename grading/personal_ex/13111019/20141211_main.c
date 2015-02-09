#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10

void beep(int length) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(length);
  BuzzerStop();
  Wait(100);
}

void led(int sayuu) {
  LED(sayuu);
  Wait(300);
  LED(0);
  Wait(300);
}

int average(int a[], int from, int to) {
  int ret=0;
  int i;

  for (i=from; i<to; i++) {
    ret += a[i];
  }
  return ret/(to-from);
}

int color(int n){
	int c[n];
	int i;
	for(i=0;i<n;i++){
		c[i]=ADRead(0);
		Wait(100);
	}
	return average(c,0,n);
}
void measure(void){
	int c;
	int h;
	int d;
	while(1){
		beep(300);
		Wait(1000);
		c=color(N);
		h=c /100;
		d=c % 10;
		while(h>0){
			led(1);
			h--;
		}
		while(d>0){
			led(2);
			d--;
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    measure();

	return 0;
}

