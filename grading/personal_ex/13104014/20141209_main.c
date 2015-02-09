#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define l 10030
#define r 10000
#define Black 500
void motor(int LEFT,int RIGHT){
	Mtr_Run_lv(LEFT,-RIGHT,0,0,0,0);

}
void stop(){
	motor(0,0);
}
void step(){
	motor(l,r);
	stop();
	Wait(100);
}
void streight(){
	motor(l,r);
	Wait(1000);
}
void left(){
	motor(l/2,0);
	Wait(100);
}
void right(){
	motor(0,r/2);
	Wait(100);
}
void length(){

}
void slalom(){
	unsigned short left;
	unsigned short right;
	for(;;){
		left =ADRead(0);
		right=ADRead(1);
		if(left>Black && right>Black){
			step(2);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

