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

#define MM 20       // 1mm 進むための時間
#define BLACK 700   // 白黒判断の境界値
#define GRAY 100

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
        motor(-LEFT_POWER,RIGHT_POWER);
    } else if (dir == RIGHT) {
        LED(LED_RIGHT);
        motor(LEFT_POWER,-RIGHT_POWER);
    }
}

void step(int n) {
    forward(n); // forward nmm
    stop();
}

int is_black(uint8_t n) {
    return ADRead(n)>=BLACK ;
}

int is_white(uint8_t n) {
    return  ADRead(n)<=GRAY;
}

int is_gray(uint8_t n) {
    return  ADRead(n)<BLACK&&ADRead(n)>GRAY ;
}

void slalom(void){
    for (;;) {
        if (is_gray(LEFT) && is_gray(RIGHT)) {
        	LED(LED_LEFT + LED_RIGHT);
            step(5);
        } else if (is_white(LEFT)) {
        	LED(LED_LEFT + LED_RIGHT);
            turn(RIGHT);
        } else if (is_white(RIGHT)) {
        	LED(LED_LEFT + LED_RIGHT);
            turn(LEFT);
        } else {
            ;
        }
    }
}



int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);


    for (;;) {
    	        if (is_white(LEFT) && is_white(RIGHT)) {
    	            step(5);
    	        } else if (is_black(LEFT) && is_black(RIGHT)) {
    	        	int blacks=0;
    	        		for(;;){
    	        		if(is_black(LEFT) && is_black(RIGHT)){
    	        			blacks+=1;
    	        			step(5);
    	        			if(blacks>10){
    	        				break;
    	        			}else{
    	        				;
    	        			}
    	        			}else{
    	        				step(5);
    	        			}
    	        		}

    	        } else if (is_black(LEFT)) {
    	            turn(LEFT);
    	        } else if (is_black(RIGHT)) {
    	            turn(RIGHT);
    	        } else if(is_gray(RIGHT)||is_gray(LEFT)){
    	            slalom();
    	        }
    	    }

    stop();


    return 0;
}
