#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10


int average(int x[],int from,int to){

	int ret=0;
	int i;

	for(i=from;i<to;i++){
		ret += x[i];

	}

	return ret/(to-from);
}



int color(int n){

	int c[n];
	int i;


	for(i=0;i<n;i++){
		c[i] = ADRead(0);
		Wait(200);

	}

	return average(c,0,n);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	int a;
	int b;
	int c;


	while(1){

		a = color(N);
		b = a/100;
		c = a%10;

		while(b>0){

			LED(2);
			Wait(200);
			LED(0);
			Wait(200);
			b--;

		}
		while(c>0){

			LED(3);
			Wait(100);
			LED(0);
			Wait(100);
			c--;

		}
	}

	Wait(1000);
	return 0;
}



