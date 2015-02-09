#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  20000
#define RIGHT_POWER 20000
#define LEFT    1
#define RIGHT   0

#define DURATION 400
#define PAUSE 100
#define VOL 100
#define PITCH 179

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
    forward(n); // forward nmm
    stop();
}

void buzzer(void){
	 BuzzerSet(PITCH, VOL);
	        BuzzerStart();
	        Wait(DURATION);
	        BuzzerStop();

}

int blacks;
int is_black(uint8_t n) {
    return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
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
	        	 blacks += 1;
	        	 step(5);
	         if (blacks > 20) { // 長いな。
	        	                stop();
	        	                buzzer();
	        	                break;
	        	            } else if (blacks >= 4) { // 中ぐらい？
	        	                ;
	        	            } else { // 短いぞ？
	        	                ;

	        	        }
	        // このときどうするか？
	        } else if (is_black(LEFT)) {
	            turn(LEFT);
	        } else if (is_black(RIGHT)) {
	            turn(RIGHT);
	        } else {
	            stop(); // 安全のための else
	        }
	    }
	    stop();
	    return 0;
	}



