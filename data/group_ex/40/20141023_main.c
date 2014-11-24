#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define r 0.013
void foward(int x,float v){
	if(v>=3.2767){
		v=3.2767;
	}else if(v<=-3.2767){
		v=-3.2767;
	}
	Mtr_Run_lv(10000*v,-10000*v,0,0,0,0);
	Wait(x/r/v);
}
void turn_right(float a){
	Mtr_Run_lv(32767,32767,0,0,0,0);
	Wait(2*a);
}
void stop(int x){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(x);
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(2000);
	int i;
	for(i=0;i<4;i++){
		foward(30,1);
		stop(2000);
		turn_right(90);
	}
	stop(0);
	return 0;
}
