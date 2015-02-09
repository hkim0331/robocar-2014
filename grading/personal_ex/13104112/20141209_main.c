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

void turn(int8_t dir) {
    if (dir == LEFT) {
        LED(LED_LEFT);
        motor(LEFT_POWER/3,RIGHT_POWER);
    } else if (dir == RIGHT) {
        LED(LED_RIGHT);
        motor(LEFT_POWER,RIGHT_POWER/3);
    }
}

void roll(int8_t dir) {
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

int is_black(int8_t n) {
    return ADRead(n) > BLACK;
}

int is_white(int8_t n) {
    return ! is_black(n);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(1000);
	    for (;;) {
	        if (is_white(LEFT) && is_white(RIGHT)) {
	            step(5);
	            Wait(500); // この Wait() は動作が完成したら削ろう。
	        } else if (is_black(LEFT) && is_black(RIGHT)) {
	        	int blacks=0;
	        	blacks +=1;
	        	step(1);
	        	if (blacks>60) {
	        		roll(RIGHT);
	        		step(5);
	        	} else if (blacks<60) {
	        		;
	        	}
	        }// このときどうするか？
	          else if (is_black(LEFT)) {
	               turn(LEFT);
	        } else if (is_black(RIGHT)) {
	               turn(RIGHT);
	               if (is_black(RIGHT)) {
	            	   roll(RIGHT);
	            	   step(5);
	               } else if (){
	            	   ;
	               }
	        } else {
	               ; // 安全のための else
	           }
	    }


	return 0;
}


