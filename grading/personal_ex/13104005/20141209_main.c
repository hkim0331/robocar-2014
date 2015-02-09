#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  12000
#define RIGHT_POWER 12000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20
#define BLACK 500
#define GRAY 200

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

void gforward(int mm){
    LED(LED_LEFT + LED_RIGHT);
    motor(LEFT_POWER/2, RIGHT_POWER/2);
    Wait(MM * mm);
    stop();
    LED(0);
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

void gturn(uint8_t dir) {
    if (dir == LEFT) {
        LED(LED_LEFT);
        motor(LEFT_POWER/6,RIGHT_POWER/2);
    } else if (dir == RIGHT) {
        LED(LED_RIGHT);
        motor(LEFT_POWER/2,RIGHT_POWER/6);
    }
}

void step(int n) {
    forward(n);
    stop();
}

void gstep(int n) {
	gforward(n);
	stop();
}

int is_black(uint8_t n) {
    return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
    return ADRead(n)<GRAY;
}

int is_gray(uint8_t n){
	return ADRead(n)>GRAY&&ADRead(n)<BLACK;
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int n;
	n=0;
    Wait(1000);
    for (;;) {
        if (is_white(LEFT) && is_white(RIGHT)) {
            step(5);
        } else if (is_black(LEFT) && is_black(RIGHT)) {
            step(5);
            n=n+1;
            if (n>=5){
            	stop();
            	break;
            } else {
            	n=0;
            }
        } else if (is_black(LEFT)) {
            turn(LEFT);
        } else if (is_black(RIGHT)) {
            turn(RIGHT);
        } else if (is_gray(LEFT) && is_gray(RIGHT)){
        	for (;;){
        		if (is_gray(LEFT) && is_gray(RIGHT)){
        			gstep(5);
        		} else if (is_white(RIGHT)){
        			turn(LEFT);
        		} else if (is_white(LEFT)){
        			turn(RIGHT);
        		} else if (is_white(LEFT)&&is_white(RIGHT)){
                    break;
        		}
        	}
        }
    }
	return 0;
}

