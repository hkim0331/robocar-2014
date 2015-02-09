#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT    1
#define RIGHT   0

void beep(void) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(100);
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

int average(void) {
	int x[10];
	int i;

	for (i=0;i<10;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,10)/10;
}
int is_white(int n) {
	return ADRead(n) < 200;
}
void color1(void) {
	int i;
	int n=average();

	for (i=0; i<n; i+=3) {
		beep();
		Wait(300);
	}
}

void color2(void) {
	int i;
	int n=average();

	for (i=0; i<n; i+=100) {
		beep();
		Wait(300);
	}
}

void color(void){
	if(is_white(LEFT) && is_white(RIGHT)){
		color1();
	}
	else{
		color2();
	}

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	for(;;){
		Wait(1000);
		color();
		Wait(1000);
	}
	return 0;
}

//赤63 黄66 白69 青75 緑400 グレー700 黒1000
