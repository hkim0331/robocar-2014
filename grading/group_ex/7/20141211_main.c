#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(int l) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(l);
  BuzzerStop();
  Wait(100);
}
int average(int a[],int start,int finish) {
  int r =0;
  int i;

  for (i=start;i<finish;i++) {
    r += a[i];
  }
  return r/(finish-start);
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
	int h;
	int z;

	while(1){
		Wait(1000);
		c = color(10);
		h = c/100;
		z = c%10;
		while(h>0){
			beep(500);
			LED(0);
			h--;
			Wait(200);
		}
		while(z>0){
			beep(250);
			LED(1);
			z--;
		}
	 }

	return 0;
}

