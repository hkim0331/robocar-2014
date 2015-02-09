#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LED_LEFT 2
#define LED_RIGHT 1

#define LEFT_POWER 10000
#define RIGHT_POWER 10000

#define LEFT 1
#define RIGHT 0

#define MM 20
#define BLACK 100


void buzzer(void){
	BuzzerSet(120, 30);
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
}


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

void black5(int n)
{
	int a[n];
	int i;
	for(i=0; i<n; i++){
		step(5);

		if (is_black(LEFT) && is_black(RIGHT)){
			a[i]=1;
		}
		else{
			a[i]=0;
		}
	}
	if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==1 && a[4]==1 && a[5]==1){
		buzzer();
	    stop();
	}
}  //step連続で5回とも黒認識ならブザーならしてストップ

int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    Wait(1000);
    for(;;){
    if(is_white(LEFT) && is_white(RIGHT)){
    	step(5);
    }else if(is_black(LEFT) && is_black(RIGHT)){
    	black5(10);
    }else if(is_black(LEFT)){
    	turn(LEFT);
    }else if(is_black(RIGHT)){
    	turn(RIGHT);
    }else{
    	stop();
    }
    }
    		stop();
    		return 0;
}


