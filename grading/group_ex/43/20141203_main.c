#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(int a){
	BuzzerSet(a,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(200);
}
int count(int n,int a,int b){
	int i;
	for (i=0; i<a; i+=b){
		LED(n);
		beep(n*100);
		Wait(500);
	}
	return 0;
}
int sum(int a[], int from, int to){
	int ret=0;
	int i;
	for (i=from; i<to; i++){
		ret += a[i];
	}
	return ret;
}
int average(int n){
	int x[n];
	int i;
	for (i=0;i<n;i++){
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,n)/n;
}
void color(void){
	int l=average(10);
	int m=l%100;
	int n=m%10;
	count(1,l,100);
	count(3,m,10);
	count(2,n,1);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}
//白60
//赤70
//黄70
//青80
//緑280
//グレー460
//黒900
