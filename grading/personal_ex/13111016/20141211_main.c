#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10

void deep(void){
	BuzzerSet(200,200);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}

int average(int a[], int from, int to){
	int ret=0;
	int i;
	for(i=from; i<to; i++){
		ret+= a[i];
	}
	return ret/(to-from);
}

int color(void){
	int n;
	int b[n];
	int i;


	for(i=0; i<n; i++){
		b[i] = ADRead(0);
	}
	return average(b,0,N);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);



	int c;
	int h;
	int d;

	while (1){
		Wait(1000);
		c = color();
		h = c / 100;
		d = c % 10;
	while (h>0){
			deep();
			d--;
		}

	}


	return 0;
}




