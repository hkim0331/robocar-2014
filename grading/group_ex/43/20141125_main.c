#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
int R = 6000; //one side motor voltage
int L = 6000; //other side motor voltage
int W;
int i;
int n;
int count = 0;
int colorblack = 800;
//int colorgray = 600;
int colorwhite = 700;
unsigned short left;
unsigned short right;

void step(R,L,W){
	Mtr_Run_lv(R, -L, 0, 0, 0, 0);
	Wait(W);
}
void stop(){
	step(0,0,100);
}
void straight(){
	step(R,L,300);
	stop();
}
void WBturnR(){
	step(R+6000,L,30);
}
void WBturnL(){
	step(R,L+6000,30);
}
void BWturnR(){
	WBturnL();
}
void BWturnL(){
	WBturnR();
}
void buzzer(n){
	for(i=0;i<n;i++){
		BuzzerSet(179,100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
	}
}
void runwhite(){
	LED(0);
	straight();
	if(left>colorblack){
		LED(1);
		WBturnR();
	}
	else if(right>colorblack){
		LED(2);
		WBturnL();
	}
}
void runblack(){
	count=0;
	for(;;){
		LED(3);
		Wait(100);
		LED(0);
		left = ADRead(0);
		right = ADRead(1);
		straight();
		if((left<colorwhite ) && (right<colorwhite)){
			buzzer(2);
			break;
		}
		if(left<colorwhite){
			LED(1);
			BWturnR();
		}
		if(right<colorwhite){
			LED(2);
			BWturnL();
		}
		count++;
	}
}
void run(){
	for(;;){
		left = ADRead(0);
		right = ADRead(1);
		if((left>colorblack) && (right>colorblack)){
			runblack();
		}
		if((left<colorwhite ) && (right<colorwhite) && (count<40) && (count>5)){
			break;
		}
		if((count<40) && (count>10)){	//test
			buzzer(1);
		}
		runwhite();
	}
	buzzer(3);
	stop();
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run();
	return 0;
}
