#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  11000
#define RIGHT_POWER 10000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20       // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値
#define G 250

#define PAUSE 200
#define VOL 100
#define DURATION 500
#define pitch 100
int duration = DURATION;
int pause    = PAUSE;
#define blacks 3
int count=0;
int n=0;
int i=0;
void motor(short left, short right) {
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
    motor(0,0);
}

void forward(int mm) {
    //LED(LED_LEFT + LED_RIGHT);
    motor(LEFT_POWER, RIGHT_POWER);
    Wait(MM * mm);
    stop();
}

void turnL(void){
	motor(LEFT_POWER/3, 0);
	Wait(2);
}
void turnR(void){
	motor(0, RIGHT_POWER/3);
	Wait(5);
}
void led(void){
	LED(LED_LEFT + LED_RIGHT);
	Wait(duration);
	LED(0);
}
void step(int n) {
    forward(n); // forward nmm
    stop();
}

void buzzer(void){
	BuzzerSet(pitch, VOL);
	BuzzerStart();
	Wait(duration);
	BuzzerStop();
	Wait(pause);
}
int is_black(uint8_t n) {
    return ADRead(n) > BLACK;
}
int is_g(int n){
	return ADRead(n) > G;
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
        	stop();
        	/*if(count !=0){
        	for(n=0;n<count;n++){
				led();
				buzzer();
			}
        	}
        	if(count>=blacks&&count<=blacks+2){
				break;
			}*/
            step(6);
            count=0;
        } else if (is_black(LEFT) && is_black(RIGHT)) {
            step(4);
        	count +=1;
        } else if (is_black(LEFT)) {
            turnR();
            led();
            count=0;
            i +=1;
            if(i>1){
            	motor(0, RIGHT_POWER);
            	Wait(50);
            }
        } else if (is_black(RIGHT)) {
            turnL();
            led();
            count=0;
            i +=1;
            if(i>1){
				motor(LEFT_POWER,0);
				Wait(50);
            }
        } else {
            ; // 安全のための else
        }
    }
    stop();
    return 0;
}

