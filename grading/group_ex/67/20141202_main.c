#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define pitch1 160
#define pitch2 120
#define pitch3 90


void buzzer(int a) {
	BuzzerSet(a,100);
	BuzzerStart();
	Wait(150);
	BuzzerStop();
	Wait(150);
}


int sum(int a[], int from, int to) {
	int ret=0;
	int i;

	for (i=from; i<to; i++) {
		ret += a[i];
	}
	return ret;
}

int average(void) {
	int x[5];
	int i;

	for (i=0;i<5;i+=1){
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,5)/5;
}

void color(void){
	int i,n=average();

	while(n>=100){
		buzzer(pitch1);
		n-=100;
	}

	while(n>=10){
		buzzer(pitch2);
		n-=10;
	}

	for(i=0;i<n;i++){

		buzzer(pitch3);

	}
}
	int main(void)
	{
		const unsigned short MainCycle = 60;
		Init(MainCycle);
		for( ;; ){

			color();

		}
		return 0;
	}

/* 白：56　青：61　黄：82　赤：84　緑：343　灰：494　黒：853 */
