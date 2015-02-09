#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  13000
#define RIGHT_POWER 15000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20
#define BLACK 700

#define DO 179

int blacks =0;
int i =0;

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
		motor(0,RIGHT_POWER);
		Wait(100);
		stop();
	} else if (dir == RIGHT) {
		LED(LED_RIGHT);
		motor(LEFT_POWER,0);
		Wait(100);
		stop();
	}
}

void step(int n) {
	forward(n);
	Wait(500);
}

int is_black(uint8_t n) {
	return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
	return ! is_black(n);
}

void buzzer() {
	BuzzerSet(DO,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(500);
}

void kaisuu() {
	for (i=1; i<=blacks; i++) {
		buzzer();
	}
}

void length() {

	Wait(1000);
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			step(5);
			stop();
			kaisuu();
			if ( blacks >= 5 && blacks <= 23) {
				stop();
				break;
			} else {
				;
			}
			blacks =0;
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			blacks += 1;
			step(5);
		} else if (is_black(LEFT)&& is_white(RIGHT)) {
			turn(LEFT);
			stop();
			Wait(100);
		} else if (is_black(RIGHT) && is_white(LEFT)) {
			turn(RIGHT);
			stop();
			Wait(100);
		} else {
			;
		}
	}
	stop();
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	length();

	return 0;
}

