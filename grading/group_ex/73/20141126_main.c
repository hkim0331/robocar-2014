#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void SI(void) {
	BuzzerSet(95, 100);
	BuzzerStart();
	Wait(50);

}

void step(void) {

	Mtr_Run_lv(7000, -10000, 0, 0, 0, 0);
	Wait(50);

}

void stop(void) {
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	BuzzerStop();
	LED(0);
	Wait(300);

}
void Right_Black(void) {
	Mtr_Run_lv(7200, 0, 0, 0, 0, 0);
	Wait(180);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Mtr_Run_lv(7200, -9000, 0, 0, 0, 0);
	Wait(80);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
void Left_Black(void) {
	Mtr_Run_lv(0, -9000, 0, 0, 0, 0);
	Wait(180);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Mtr_Run_lv(7200, -9000, 0, 0, 0, 0);
	Wait(80);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
void Right_Left_black(void) {
	step();
	LED(3);
	SI();
	stop();
}
int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left;
	unsigned short right;
	int i;
	int Right_Left_blacks = 0;
	int a = 0;
	for (i = 0; i < 10000; i++) {

		left = ADRead(0);
		right = ADRead(1);
		if (left < 500 && right < 500) {
			a += 1;
			if ((10 > Right_Left_blacks) && (Right_Left_blacks > 5)
					&& (a >= 1)) {
				break;
			} else {
				Right_Left_blacks = 0;
				step();
			}
		} else if (left > 500 && right < 500) {
			Right_Black();
		} else if (right > 500 && left < 500) {
			Left_Black();
		} else if (left > 500 && right > 500) {
			Right_Left_blacks += 1;
			Right_Left_black();
			a = 0;

		} else {
			;
		}
	}

	return 0;
}

