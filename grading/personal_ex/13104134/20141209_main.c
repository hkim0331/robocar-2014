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

#define MM 20
#define BLACK 800
#define G 300

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

void turn(int dir) {
    if (dir == LEFT) {
        LED(LED_LEFT);
        motor(LEFT_POWER*0,RIGHT_POWER);
    } else if (dir == RIGHT) {
        LED(LED_RIGHT);
        motor(LEFT_POWER,RIGHT_POWER*0);
    }
}

void step(int n) {
    forward(n);
    Wait(10);
    stop();
}

int is_black(int n) {
    return ADRead(n) > BLACK;
}

int is_white(int n) {
    return ! is_black(n);
}

int is_G(int n){
	return ADRead(n) > G;
}

int blacks=0;

int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    Wait(1000);
    for (;;) {
        if (is_white(LEFT) && is_white(RIGHT)) {
            step(30);
            blacks=0;
        } else if (is_black(LEFT) && is_black(RIGHT)) {
        	blacks += 1;
            step(10);
        } else if (blacks==4){
        	turn(RIGHT);
        	Wait(500);
        } else if (is_black(LEFT)) {
            turn(LEFT);
            blacks=0;
        } else if (is_black(RIGHT)) {
            turn(RIGHT);
            blacks=0;
        } else if (is_G(LEFT) && is_white(RIGHT)){
        	turn(LEFT);
        } else if (is_G(RIGHT)&&is_white(LEFT)){
        	turn(RIGHT);
        } else if(blacks==8){
        	step(500);
        	stop();
        } else {
            ;
        }
    }
    stop();
    return 0;
}

