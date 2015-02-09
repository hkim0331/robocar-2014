#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define w 500
#define z 100

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(z);
  BuzzerStop();
  Wait(z);
}

void LED1(){

    LED(1);
    Wait(w);
    LED(0);
}

void LED2(){

    LED(2);
    Wait(w);
    LED(0);
}


int average(int a[], int from, int to){
	int ret=0;
	int i;

	for(i=from; i<to; i++){
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
	return average(c,0,n)/n;
}

int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);
      int a;
      int b;
      int c;

      While(1){
    	  Wait(1000);

    	  a = color;
    	  b = a/100;
    	  c = a%10;
    	  While (h>0){
    		  beep();
    		  c--;
    	  }
      }

    return 0;
    }




