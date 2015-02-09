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

#define MM 15       // 1mm 進むための時間
#define BLACK 800   // 白黒判断の境界値
#define TOO_MANY 10	//黒→黒の回数(始めの白→黒を含む)

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

void turn(char dir) {
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

char is_meian(char dir) {
	char i;
	i = ADRead(dir) > BLACK;
	//i=0,1 0==>白 1==>黒
	return i;
}

void buzzer_times(int n) {
	int i;
	for(i=0; i>n; i++) {
		BuzzerSet(100, 100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
		Wait(50);
	}
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int blacks=0;
	Wait(1000);
	for (;;) {
		if (is_meian(LEFT)==0 && is_meian(RIGHT)==0 ) {
			step(5);
			Wait(100); // この Wait() は動作が完成したら削ろう。

			if(blacks != 0) {
				buzzer_times(blacks);
				if(blacks < TOO_MANY){
					break;
				}
			}
		} else if (is_meian(LEFT)==1 && is_meian(RIGHT)==1) {
			blacks++;
			step(5);
			Wait(500);
		} else if (is_meian(LEFT)==1) {
			turn(LEFT);
		} else if (is_meian(RIGHT)==1) {
			turn(RIGHT);
		} else {
			;
		}
	}
	stop();
	return 0;
}
