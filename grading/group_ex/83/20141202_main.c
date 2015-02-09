#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void beep100(void) {
	BuzzerSet(100,100);
    BuzzerStart();
    Wait(300);
    BuzzerStop();
    Wait(200);
}

void beep10(void) {
	BuzzerSet(200,100);
    BuzzerStart();
    Wait(300);
    BuzzerStop();
    Wait(200);
}

void beep1(void) {
	BuzzerSet(300,100);
    BuzzerStart();
    Wait(300);
    BuzzerStop();
    Wait(200);
}


void led(void) {
	LED(3);
	Wait(200);
	LED(0);
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

int average(void) {
	int x[5];
	int i;

	for (i=0;i<5;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,5)/5;
}
void color(void) {
	int i, a, b, c, d;
	int n=average();
	a=n/100;
	b=n%100;
	c=b/10;
	d=b%10;

    for (i=0; i<a; i+=1) {
    	beep100();
    }
    for (i=0; i<c; i+=1) {
      	beep10();
    }
    for (i=0; i<d; i+=1) {
    	beep1();

    }
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

{
	color();

}
	return 0;
}



白　51
赤　52
黄　53
青　54
灰　441
黒　907
