#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define BLACK 300
#define WHITE 100

#define MM 20
void motor(short l, short r){
	Mtr_Run_lv(l,r,0,0,0,0);
}
void forward(){
	motor(10000,-10000);
}

void tright(){
	motor(10000,10000);
}

void tleft(){
	motor(-10000,-10000);
}

void slowleft(){
	motor(2000,-2000);
}

void slowright(){
	motor(2000,2000);
}

void stop(){
	motor(0,0);
}

void buzzer(){
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
}

void wait_until_sw_on(void){
	for(;;){
		if(getSW()==1){
			break;
		}
	}
}

void wait_until_sw_off(void){
	for(;;){
		if(getSW()==0){
			return;
		}
	}
}

void wait_on_off_and(int n){
	wait_until_sw_on();
	LED(3);
	wait_until_sw_off();
	LED(0);
	Wait(n*1000);
}

void start(void){
	wait_on_off_and(1);
	forward();
}

void hasiru(void){
	unsigned short left;
	unsigned short right;
	for(;;){
		left=ADRead(0);
		right=ADRead(1);
	}

}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

