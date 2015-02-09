#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER 10000
#define RIGHT_POWER 9000
#define LEFT 1
#define RIGHT 0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 10       // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値
#define WHITE 250

#define WAIT_TIME 1000

void motor(short left, short right) {
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
    motor(0,0);
    Wait(500);
}

void forward(void) {
    LED(0);
    motor(LEFT_POWER, RIGHT_POWER);
}

void turn(uint8_t dir) {
    if (dir == LEFT) {
        LED(LED_LEFT);
        motor(0, RIGHT_POWER * 2);
    } else if (dir == RIGHT) {
        LED(LED_RIGHT);
        motor(LEFT_POWER * 2, 0);
    }
}
void set(int mm) {
    LED(LED_LEFT + LED_RIGHT);
    motor(LEFT_POWER, RIGHT_POWER);
    Wait(MM * mm);
}

void step(int n) {
    set(n);
    stop();
}

int is_gray (uint8_t n){
	return ADRead(n) > WHITE && ADRead(n) < BLACK;
}

int is_black(uint8_t n) {
    return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
    return ADRead(n) < WHITE;
}

void go(void) {
	int blacks = 0;
	for (;;) {
	    if (is_gray(LEFT) && is_gray(RIGHT)) {
		    motor(LEFT_POWER/2, RIGHT_POWER/2);
		    LED(0);
	    } else if (is_gray(LEFT) && is_white(RIGHT)) {
		    turn(LEFT);
	    } else if (is_white(LEFT) && is_gray(RIGHT)) {
		    turn(RIGHT);
	    } else {
	        if (is_white(LEFT) && is_white(RIGHT)) {
	            forward();
		    } else if (is_black(LEFT) && is_black(RIGHT)) {
	            blacks += 1;
	    	    step(MM);
	    	        if(blacks >= 18){
	    		        break;
	    	        } else if (blacks == 5) {
	    		        turn(LEFT);
	    		        Wait(400);
	    	        } else {
	    		        ;
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
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    Wait(WAIT_TIME);
    go();
    stop();

	return 0;
}

