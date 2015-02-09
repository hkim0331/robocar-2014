#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT	1
#define RIGHT	0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20 		// 1mm 進むための時間
#define BLACK 500 	// 白黒判断の境界値

#define DT 100
#define B 8

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
	forward(n); // forward nmm
	stop();
}

int is_black(uint8_t n) {
	return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
	return ! is_black(n);
}
void flash(void) {
	/*
	LED(3);
	Wait(DT);
	LED(0);
	Wait(DT);
	*/
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(DT);
	BuzzerStop();
	Wait(DT);
}
int check(int bk, int b) {
	int i;

	for (i=0;i<bk;i++) {
		flash();
	}
	return b-3 < bk && bk < b+3;
}

void epilog(int n) {
	int i;
	for (i=0;i<n;i++) {
		LED(3);
		Wait(100);
		LED(0);
		Wait(100);
	}
}
int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int blacks;

	Wait(1000);
	blacks=0;
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			if (check(blacks,B)){
				break;
			}
			blacks = 0;
			step(5);
			Wait(DT*5);
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			blacks += 1;
			step(5);
			Wait(DT);
		} else if (is_black(LEFT)) {
			if (check(blacks,B)){
				break;
			}
			blacks = 0;
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			if (check(blacks,B)) {
				break;
			}
			blacks = 0;
			turn(RIGHT);
		} else {
			; // 安全のための else
		}
	}
	stop();
	epilog(100);
	return 0;
}
