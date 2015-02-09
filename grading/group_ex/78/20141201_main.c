#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT    1
#define RIGHT   0
#define LED_LEFT 2
#define LED_RIGHT 1
#define MM 15
#define BLACK 600

void oto(int blacks){
	int i;
	for(i=0;i<blacks;i++){
		BuzzerSet(179,100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
		Wait(100);
	}
}
void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}
void stop(void) {
	motor(0,0);
}
void forward(int mm) {
	LED(LED_LEFT + LED_RIGHT);
	motor(LEFT_POWER, RIGHT_POWER);
	Wait(MM * mm);
	stop();
}
void step(int n) {
	Wait(500);
	forward(n);
}
int is_black(int n) {
	return ADRead(n) > BLACK;
}
int is_white(int n) {
	return ! is_black(n);
}
int judge(){
	int blacks=0;
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			step(5);
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			blacks += 1;
			step(5);
			if(is_white(LEFT) || is_white(RIGHT)){
				break;
			}else{;}
		}
		stop();
		oto(blacks);
	}}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int j;
	Wait(100);
	for(j=0;j<3;j++){
		judge();
	}
	return 0;
}
