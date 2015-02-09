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
#define BLACK 500

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

int is_black(int n) {
    return ADRead(n) > BLACK;
}

int is_white(int n) {
    return ! is_black(n);
}



void slalom(void){
    for (;;) {
        if (is_white(LEFT) && is_white(RIGHT)) {
            step(5);
        } else if (is_black(LEFT) && is_black(RIGHT)) {
        	break;
        } else if (is_black(LEFT)) {
            turn(LEFT);
        } else if (is_black(RIGHT)) {
            turn(RIGHT);
        } else {
            ;
        }
    }
}

void rength(void){

	for(;;){
	if(is_black(LEFT) && is_black(RIGHT)){
		blacks+=1;
		step(5);
	}else{
	break;
	}

	}
}
int main(void) {
	    const unsigned short MainCycle = 60;
	    Init(MainCycle);
	    for(;;){
	    int blacks =0;
	    slalom();
	    rength();
	    if(blacks<=20&&blacks>4){
	    	break;
	    }else{
	    	;
	    }
	    }
	stop();
	return 0;
	}


