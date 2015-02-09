#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void beep1(void) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}

void beep2(void) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(200);
	BuzzerStop();
	Wait(200);
}

void beep3(void) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(300);
	BuzzerStop();
	Wait(300);
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
	int x[10];
	int i;

	for (i=0;i<10;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,10)/10;
}

void color1(void) {
	int i;
	int n=average();

	for (i=0; i<n; i+=100) {
		beep1();
	}
}

void color2(void) {
	int i;
	int n=average();
    int a;

    a=n%100;

	for (i=0; i<a; i+=10) {
		beep2();
	}
}

void color3(void) {
	int i;
	int n=average();
int b,c;
b=n%100;
c=b%10;

	for (i=0; i<c; i+=1) {
		beep3();
	}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color1();
	color2();
	color3();

}

//白　黄色　青　赤　緑　灰色　黒  //








