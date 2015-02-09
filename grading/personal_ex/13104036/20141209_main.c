#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
int R = 7400; //one side motor voltage
int L = 7000; //other side motor voltage
int colorblack = 700;
int colorwhite = 450;
int b1 = 4;	//最後の手前で右へクランチ
int b2 = 7;	//最後の手前で直進
int b3 = 8;	//最後の停止
int countb;
unsigned short left;
unsigned short right;

void step(int r, int l,int w){
	Mtr_Run_lv(r, -l, 0, 0, 0, 0);
	Wait(w);
}
void stop(){
	step(0,0,100);
}
void straight(int W){
	step(R,L,W);
}
void turnR(){
	step(R+7000,L,30);
}
void turnL(){
	step(R,L+7000,30);
}
void crankR(){
	step(0,L+7000,2000);
}
void buzzer(int n){
	int i;
	for(i=0;i<n;i++){
		BuzzerSet(179,100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
		Wait(100);
	}
}
void rungray(){
	R=R/2;
	L=L/2;
	for(;;){
		left = ADRead(0);
		right = ADRead(1);
		if((left<colorwhite ) && (right<colorwhite)){
			break;
		}
		else if(right<colorwhite){
			turnL();
		}
		else if(left<colorwhite){
			turnR();
		}
		straight(100);
	}
}
void runwhite(){
	straight(30);
	if(left>colorblack){
		turnR();
	}
	if(right>colorblack){
		turnL();
	}
}
void countblack(){
	LED(3);
	countb++;
	if(countb==b1){
		straight(200);
	}
	if(countb==b2){
		crankR();
	}
	if(countb==b3){
		straight(200);
	}
	straight(200);
}
void run(){
	for(;;){
		LED(0);
		left = ADRead(0);
		right = ADRead(1);
		runwhite();
		if(left>colorblack && right>colorblack){
			countblack();	//if black
		}
		if(left<colorblack && left>colorwhite && right<colorblack && right>colorwhite){
			rungray();	//if gray
		}
	}
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run();
	return 0;
}
