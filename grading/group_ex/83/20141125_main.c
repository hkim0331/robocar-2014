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
#define SO (120)

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
}

void buzzer (void)
{
    BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}

int is_black(uint8_t n) {
    return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
    return ! is_black(n);
}

int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    Wait(1000);
    for (;;) {
        if (is_white(LEFT) && is_white(RIGHT)) {
            step(3);
            Wait(500);
        } else if (is_black(LEFT) && is_black(RIGHT)) {
        	int blacks = 0;
        	blacks += 1;
        	step(3);
        	buzzer();

        	if (blacks > 15) {
        	step(3);
        	blacks = 0;
        	break;
        	} else if (blacks >= 3) {
        	stop();
        	} else {
        	;
        	}
        	}

        }if (is_black(LEFT)) {
            turn(LEFT);
        } else{
        	;
        }if (is_black(RIGHT)) {
            turn(RIGHT);
        } else {
            ;
        }
	return 0;

}

