#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  9000
#define RIGHT_POWER 9400
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 14       // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値

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
int count=0;
int i;
void Buzzer(count){
	BuzzerSet(179,100);
    for(i=0;i<count/2;i++){
		BuzzerStart();
		Wait(250);
		BuzzerStop();
		Wait(250);
	}
}

void RUN(){

	int blacks=0;

	Wait(1000);
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			LED(LED_LEFT + LED_RIGHT);
			step(5);
			Wait(250);
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			count += 1;
			blacks += 1;
			step(5);
			Wait(250);
			LED(blacks%2+1);
			if (blacks > 46) {
				stop();
				LED(0);
				Buzzer(count);
				break;
			} else if((is_white(LEFT) && is_white(RIGHT))||
					   (is_black(LEFT) && is_white(RIGHT))||
					   (is_white(LEFT) && is_black(RIGHT))) {
					Wait(1000);
				    Buzzer(count);
				    count=0;
			}
		} else if (is_black(LEFT)) {
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			turn(RIGHT);
		} else {
			;
		}
	}

	stop();

}
int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	RUN();

	return 0;
}
