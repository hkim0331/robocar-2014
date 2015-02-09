#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 10000

#define MM 20       // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値
#define GRAY 300

#define LEFT    1
#define RIGHT   0

#define LED_LEFT    2
#define LED_RIGHT   1

void motor(short left, short right) {
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
    motor(0,0);
}

void forward(int mm) {
    motor(LEFT_POWER, RIGHT_POWER);
    Wait(MM * mm);
    stop();
    if(Gray(LEFT) && Gray(RIGHT)){
    	motor(LEFT_POWER/2, RIGHT_POWER/2);
    }else{

    }
}

void turn(uint8_t dir) {
    if (dir == LEFT) {
        motor(LEFT_POWER/3,RIGHT_POWER);
    } else if (dir == RIGHT) {
        motor(LEFT_POWER,RIGHT_POWER/3);
    }
}

void step(int n) {
    forward(n); // forward n=mm
    stop();
}

int Black(int n) {
    return ADRead(n) > BLACK;
}

int White(int n) {
    return ! Black(n) && ! Gray(n);
}

int Gray(int n) {
    return ADRead(n) > GRAY && ADRead(n) < BLACK;
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int blacks=0;

	Wait(1000);
	for(;;){
		if(White(LEFT) && White(RIGHT)){
			forward(10000);
		}else if(Black(LEFT) && Black(RIGHT)){
			blacks += 1;
		}
	}

	return 0;
}

