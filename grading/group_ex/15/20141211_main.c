#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10

void sound(int time){
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(time);
	BuzzerStop();
	Wait(100);
}


int average(int a[], int from, int to){
	int ret=0;
	int i;
	for (i=from;i<to;i++){
		ret += a[i];
	}
	return ret/(to-from);
}

int color(int n){
	int x[n];
	int i;

	for (i=0; i<n; i++){
		x[i] =ADRead(0);
		Wait(100);
	}
	return average(x,0,n);
}

void light(void){
	int c;
    int d;
	int e;

	while (1){
		Wait(1000);
		LED(3);
		c = color(N);
		d = c /100;
		e = c % 10;
	while (d>0){
		sound(500);
		d--;
	}
	while (e>0) {
		sound(100);
		e--;
	}
		LED(0);
  }
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    light();

	return 0;
}

