#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 12000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20       // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値

#define LONGBLACK 10
#define MIDDLEBLACK 4

int blacks;
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

void whitewhite(void){
	if (is_white(LEFT) && is_white(RIGHT)) {
		            step(5);
		            Wait(500);
		        }
}
void blackblack(void){
	 step(5);
	if (is_black(LEFT) && is_black(RIGHT)) {
		           blacks += 1;
		           step(5);
		            if(blacks>LONGBLACK){
		        	   stop();
		           }else if (blacks>=MIDDLEBLACK){
		        	   ;
		           } else{
		        	   ;
		           }
		           }
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(1000);
	    for (;;) {
	    	whitewhite();
	    	blackblack();
	    if (is_black(LEFT)) {
	            turn(LEFT);
	        }  if (is_black(RIGHT)) {
	            turn(RIGHT);
	        } else {
	            ;
	        }
	    }
	    stop();
	    return 0;
	}
