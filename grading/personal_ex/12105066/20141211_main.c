#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10

void beep(int,length) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

int average (int a[],int from,int to){
	int ret=0;
	int i;
	for(i=from; i<to; i++){
		ret +=a[i];
	}
	return ret/(to-from);
}

int color (int n){
  int c[n];
  int i;

  for (i=0;i<n;i++) {}
    c[i] = ADRead(0);
    Wait(100);
  }
  return color(c,0,n);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	while(1){
		wait(1000);
		LED(3);
		c=color(N);
		h=c/100;
		m=c%10;

	while(h>0)
			beep(500);
		h--;

    while(h>0)
            beep(100);
	    d--;
	LED(0);
	}

	return 0;
}

