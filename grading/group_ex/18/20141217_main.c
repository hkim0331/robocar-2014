#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define y 500
#define z 100
#define w 500

void beep1(void){
	BuzzerSet(100,100);
	  BuzzerStart();
	  Wait(y);
	  BuzzerStop();
	  Wait(y);
}
void beep2(void) {
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

void color(int x){

	int i[x];
	int n,c,h;
	int b;
for (b=0; b<c; b++){
	i[b] = ADRead(0);
	Wait(100);
	}
n=average(i,0,100);
c=n/100;

h=(n-c*100)/10;

for(b=0; b<c; b++){
	beep1();
	LED1();
}
for(b=0;b<h;b++){
	beep2();
	LED2();
}
}
