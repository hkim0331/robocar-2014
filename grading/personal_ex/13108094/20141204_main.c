#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  8200
#define RIGHT_POWER 10000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 0
#define LED_RIGHT 1

#define MM 20       // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値

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

int is_long(int blacks){
	step(5);
	if (8 >= blacks && blacks >= 4) {
		stop();
	} else {
		;
	}
}

int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    int blacks=0;

    Wait(1000);
    for (;;) {
        if (is_white(LEFT) && is_white(RIGHT)) {
        	blacks=0;
            step(5);
            Wait(500);
        } else if (is_black(LEFT) && is_black(RIGHT)) {
            blacks+=1;
            is_long(blacks);
        } else if (is_black(LEFT)) {
        	blacks=0;
            turn(LEFT);
        } else if (is_black(RIGHT)) {
        	blacks=0;
            turn(RIGHT);
        } else {
            ;
        }
    }
    stop();
    return 0;
}
