#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(int a) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(a);
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

int average(int n) {
  int x[n];
  int i;

  for (i=0;i<n;i++) {
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,n)/n;
}

void colorbuzzer(int n,int a,int b) {
  int i;


  for (i=0; i<n; i+=a) {
    beep(b);
  }
}

  int main(void) {
	  const unsigned short MainCycle=60;
	  Init(MainCycle);

	  int i;

	 Wait(500);

	 for(;;){
		 int n=average(10);
		 int m=n%100;
		 colorbuzzer(n,100,300);
		 Wait(200);
		 colorbuzzer(m,10,100);
		 Wait(2000);
	 }
  }



/* ki ao gure aka midori */
