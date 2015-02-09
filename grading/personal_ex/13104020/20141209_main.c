#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define left_pw  8000
#define right_pw 8000
#define LEFT    1
#define RIGHT   0

#define LED_left 2
#define LED_right 1

#define MM 5        // 1mm 進むための時間
#define BLACK 200   // 白黒判断の境界値

void motor(short l, short r) {
    Mtr_Run_lv(l, -r, 0, 0, 0, 0);
}

void stop(void) {
    motor(0,0);
}

void turn(int dir) {
    if (dir == LEFT) {
        LED(LED_left);
        motor(-left_pw,right_pw);
    } else if (dir == RIGHT) {
        LED(LED_right);
        motor(left_pw,-right_pw);
    }
}

void step(int s) {
    LED(LED_left + LED_right);
    motor(left_pw,right_pw);
    Wait(MM*s);       //s[mm]進む
    stop();
}

void debuff(int d){
    LED(0);
    motor(left_pw*0.7,right_pw*0.7);
    Wait(MM*d);
    stop();
}

int is_black(int b) {
    return ADRead(b) > BLACK;
}

int is_white(int w) {
    return ! is_black(w);
}

int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);
    int blacks=0;
    Wait(1000);
    for (;;) {
        if (is_white(LEFT) && is_white(RIGHT)) {
        	if(blacks>70&&blacks<100){
        	    motor(-left_pw,-right_pw);
        	    Wait(25);
        	    stop();
        	    break;
        	}
            step(5);
            blacks = 0;
        } else if (is_black(LEFT) && is_black(RIGHT)) {
            blacks += 1;
            debuff(5);
            } else if (blacks >= 4) {
            	if (is_white(LEFT)) {
            	            turn(RIGHT);
            	        } else if (is_white(RIGHT)) {
            	            turn(LEFT);
            	        }
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
    return 0;
}
