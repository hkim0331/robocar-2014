#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define TIME 10	//センサー読み取り回数

int average(int *n,int d){	//平均計算プログラム
	int i,sum=0;
	for(i=0;i<d;i++){
		sum+=*(n+i);
	}
	return sum/d;
}

void sound(int a,int b){		//音声出力プログラム
	BuzzerSet(a,100);
	BuzzerStart();
	Wait(b);
	BuzzerStop();
	Wait(500);
}

void wake_up(void){		//電源投入確認プログラム
	int i;
	for(i=0;i<5;i++){
		LED(3);
		Wait(250);
		LED(0);
		Wait(250);
	}
}

int scan(void){	//センサー値読み取りプログラム
	return (ADRead(0)+ADRead(1))/2;
}

int read(void){	//センサー測定値出力プログラム
	int c[TIME],i;
	for(i=0;i<TIME;i++){
		c[i]=scan();
		Wait(100);
	}
	return average(c,TIME);
}

void output(int n){	//測定結果出力プログラム
	int a,b,i;
	a=n/100;
	b=(n%100)/10;
	for(i=0;i<a;i++){
		sound(179,1000);
	}
	for(i=0;i<b;i++){
		sound(90,500);
	}
}

void test(void){	//測定プログラム
	while(1){
		LED(3);
		output(read());
		LED(0);
		Wait(5000);
	}
}

int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	wake_up();
	test();
	return 0;
}

/*
 * 測定結果:
 * 赤:50
 * 青:50
 * 緑:130
 * 黄:50
 * 灰:280
 */
