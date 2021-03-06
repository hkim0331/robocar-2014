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

#define WT 100

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

void length(void) {
	int blacks = 0;

	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			blacks = 0;
			step(5);
			Wait(500);
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			blacks += 1;
			if (blacks > 6) {
				break;
			} else {
				step(5);
				Wait(100);
			}
		} else if (is_black(LEFT)) {
			blacks = 0;
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			blacks = 0;
			turn(RIGHT);
		} else {
			; // 安全のための else
		}
	}
	stop();
}

void epilog(int n) {
  while (n>0) {
    LED(3);
    Wait(100);
    LED(0);
    Wait(100);
    n -= 1;
  }
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    Wait(1000);
    length();
	epilog(10);

	return 0;
}

