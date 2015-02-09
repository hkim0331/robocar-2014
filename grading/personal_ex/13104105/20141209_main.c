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

#define MM 10       // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値
#define WHITE 250


void motor(short left, short right) {
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
    motor(0,0);
    Wait(500);
}

void forward(void) {
    LED(LED_LEFT + LED_RIGHT);
    motor(LEFT_POWER, RIGHT_POWER);
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



int is_glay (uint8_t n){
	return ADRead(n)>WHITE&&ADRead(n)<BLACK;
}

int is_black(uint8_t n) {
    return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
    return ADRead(n)<WHITE;
}


void go(void){
	for(;;){
	if(is_glay(LEFT)&&is_glay(RIGHT)){
		forward();
	}
	else if(is_glay(LEFT)&&is_white(RIGHT)){
		turn(RIGHT);
	}
	else if(is_white(LEFT)&&is_glay(RIGHT)){
		turn(LEFT);
	}
	else{
	      int blacks = 0;
	      if (is_white(LEFT) && is_white(RIGHT)) {
	        	forward();

			if (blacks>5) {
	    	    blacks=0;
	    	    break;
	        }
			else if (blacks <=4) {
				forward();
			}
			else {
				forward();
				blacks=0;
			}
		   }
	      else if (is_black(LEFT) && is_black(RIGHT)) {
	    	  blacks += 1;
	    	  forward();
	      }
	      else if (is_black(LEFT)) {
	    	  turn(LEFT);
	      }
	      else if (is_black(RIGHT)) {
	    	  turn(RIGHT);
	      }
	      else {
	    	  ;
	      }

	 }
	}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


    Wait(1000);


      go();

    stop();
	return 0;
}

