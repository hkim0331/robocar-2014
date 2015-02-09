#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beepsh(void) {
	BuzzerSet(80,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(200);
}

void deepmi(void){
	BuzzerSet(125,100);
	BuzzerStart();
	Wait(500);
	BuzzerStop();
	Wait(100);
}

void deeplo(void){
	BuzzerSet(180,100);
	BuzzerStart();
	Wait(1000);
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
	int x[5];
	int i;
	for (i=0;i<5;i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,5)/5;
}

void color(void) {
	int i;
	int n=average();

	if(n>700){
		deeplo();
		deepmi();
		for(i=0;i<n-700;i+=10) {
			beepsh();
		}}
	else if(n>300){
		deepmi();

		for(i=0;i<n-300;i+=10) {
			beepsh();
		}}
	else {
		for(i=0;i<n;i+=10) {
			beepsh();
		}}
}

int main(void){

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=0 ; i<10 ; i++){

		color();
		Wait(400);
	}


	return 0;
}


//kiiro 100
//aka 120
//midori 340
//ao110
//gre-260
//siro50
//kuro920
