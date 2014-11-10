#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void kaeru(void) {
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
}

#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT_EYE	0
#define RIGHT_EYE	1

#define MM 20 //5mm 進むための時間
#define BLACK 500 // 白黒判断の境界値

void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
	motor(0,0);
}

void forward(int mm) {
	motor(LEFT_POWER, RIGHT_POWER);
	Wait(MM * mm);
	stop();
}

void step(void) {
	forward(5); // forward 5mm
	stop();
}

int is_black_left(void) {
	return ADRead(LEFT_EYE) > BLACK;
}

int is_black_right(void) {
	return ADRead(RIGHT_EYE) > BLACK;
}

int is_black(void) {
	return (is_black_left() || is_black_right());
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for (;;) {
		step();
		Wait(500);
		if (is_black()) {
			break;
		} else {
			;
		}
	}
	kaeru();

	return 0;
}

