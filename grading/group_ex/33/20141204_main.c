#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  6000
#define RIGHT_POWER 6000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20
#define BLACK 500

#define large 30
#define small 3
#define big 15
#define W_time 1000

#define pitch 120
#define vol 100
#define B_time 200


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

void turn(uint8_t dir) {
	if (dir == LEFT) {
		LED(LED_LEFT);
		motor(LEFT_POWER/3,RIGHT_POWER);
	} else if (dir == RIGHT) {
		LED(LED_RIGHT);
		motor(LEFT_POWER,RIGHT_POWER/3);
	}
}

void step(int n) {
	forward(n);
	stop();
}

int is_black(uint8_t n) {
	return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
	return ! is_black(n);
}

void buzzer(void){
	BuzzerSet(pitch, vol);
	BuzzerStart();
	Wait(B_time);
	BuzzerStop();
}

void length(void){
	int blacks = 0;
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			step(5);
		}else if (is_black(LEFT) && is_black(RIGHT)) {
			blacks += 1;
			step(5);
			buzzer();
			if(blacks > large){
				stop();
				break;
			}if(((blacks > small) && (big > blacks)) && (is_white(LEFT) || is_white(RIGHT))) {
				stop();
				break;
			}else{
				;
			}
			if(is_white(LEFT) || is_white(RIGHT)){
				blacks = 0;
			}
		} else if (is_black(LEFT)) {
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			turn(RIGHT);
		} else {
			;
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(W_time);
	length();
	stop();
	return 0;
}

