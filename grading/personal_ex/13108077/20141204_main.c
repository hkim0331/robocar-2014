#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define R 10000
#define L 10000
void run(short a,short b){	//コード簡略用関数
	Mtr_Run_lv(a,-b,0,0,0,0);
}
void step(int t){
	run(R,L);
	Wait(t);
}
void stop(int t){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(t);
}
void wake_up(void){		//電源投入確認
	int i;
	for(i=0;i<5;i++){
		LED(3);
		Wait(250);
		LED(0);
		Wait(250);
	}
}
void test(int n){
	step(n);
	stop(0);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	wake_up();
	test(1000);
	return 0;
}
