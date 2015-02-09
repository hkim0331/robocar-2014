#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DURATION 400
#define PAUSE 100
#define VOL 100
#define DO    179
#define XX    0
#define RE 160
#define MI 142


void play(int pitch)
{
	BuzzerSet(pitch, VOL);
	BuzzerStart();
	Wait(DURATION);
	BuzzerStop();
	Wait(PAUSE);
}

void d(){
	play(DO);
}
void r(){
	play(RE);
}
void m(){
	play(MI);
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

int main(void)
{
	int i,a,b;

	const unsigned short MainCycle = 60;
	Init(MainCycle);
	a = 0;
	b = 0;


	if(100< average()){
		for (i=0; i<average()/100; i+=1) {
			d();
			a = a +1;
		}

		for(i=0; i<(average()-a*100)/10; i+=1){
			r();
			b = b +1;
		}

		for(i=0; i<(average()-a*100-b*10); i+=1){
			m();
		}
	}else if(10<average() && average()<100){

		for(i=0; i<(average()/10); i+=1){
			r();
			b = b +1;
		}

		for(i=0; i<(average()-b*10); i+=1){
			m();
		}
	}else{
		for(i=0; i<average(); i+=1){
			m();
		}
	}



	return 0;
}
//白(58)<赤(59)<黄(60)<青(64)<緑(337)<グレー(558)<黒(874)//

