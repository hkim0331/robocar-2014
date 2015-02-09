#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 10000

int moter(int left,int right){
	Mtr_Run_lv(right,-left,0,0,0,0);
}

int go(void){
	motor(RIGHT,-LEFT);
}

int Buzzer(int pitch, int vol, int DURATION){
	BuzzerSet(pitch, vol);
	BuzzerStart();
	Wait(DURATION);
	BuzzerStop();
}

int lefturn(void){
	motor(RIGHT,0);
}

int rightturn(void){
	motor(0,LIGHT);
}

int stop(void){
	motor(0,0);
}

int step(void){
	int i;
	while(1){
		go(10000,10000);
		Wait(300);
		go(0,0);
		Wait(300);
	}
}

int main(void)
{

}
