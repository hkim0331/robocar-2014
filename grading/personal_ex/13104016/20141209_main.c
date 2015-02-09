#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


int R = 6000;
int L = 6000;
int count = 0;
int colorblack = 800;
int colorgray = 600;
int colorwhite = 200;
int countb1=;
unsigned short left;
unsigned short right;



void step(R,L,W){
	Mtr_Run_lv(R, -L, 0, 0, 0, 0);
	Wait(W);
}
void straight(){
	step(6000,6000,0);
}
void turnR(){
	step(12000,6000,30);
}
void turnL(){
	step(6000,12000,30);
}


void buzzer(int n){
	int i;
	for(i=0; i<n; i++){
		BuzzerSet(n,100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
		Wait(100);
	}
}

void rungray{
	for(;;){
		left=ADRead(0);
		right=ADRead(1);
		if(left<colorwhite && right<colorwhite){
			break;
		}
	}
}

void countblack(){
	int countb++;
	if (countb==b1){
		straight(200);
	}

	if (countb==b2){
	}

	if (countb=b3){

	}


}
void run(){
	for(;;){
		left=ADRead(0);
		right=ADRead(1);
		if(left<colorblack && left>colorwhite && right<colorwhite && right>colorwhite){
			rungray();
		}
	}
}
void stop(){
	step(0,0,0);
}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);




	return 0;
}

