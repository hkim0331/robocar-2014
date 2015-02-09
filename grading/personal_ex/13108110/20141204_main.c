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

void step(int n) {
    forward(n);
    stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			step(5);
			Wait(500);
		} else if (is_black(LEFT) && is_black(RIGHT)) {

			step(5);
			if (blacks > 20) {
				stop();
			break;
			} else if (blacks >= 4) {
				;
			} else {
				;
			}
	        	;
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

