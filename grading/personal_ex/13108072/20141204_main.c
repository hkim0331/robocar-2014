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

void turn(char dir) {
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

char is_meian(char dir) {
	char i;
	i = ADRead(dir) > BRACK;
	//i=0,1 0==>白 1==>黒
	return i;
}


int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    Wait(1000);
    for (;;) {
        if (is_meian(LEFT) && is_meian(RIGHT) ) {
            step(5);
            Wait(500); // この Wait() は動作が完成したら削ろう。
        } else if (is_black(LEFT) && is_black(RIGHT)) {
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
