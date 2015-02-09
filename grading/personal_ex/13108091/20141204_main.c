#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT_EYE    0
#define RIGHT_EYE   1

#define MM 10 //5mm 進むための時間
#define NN 10 //1°曲がるための時間
#define BLACK 600 // 白黒判断の境界値

#define LED_LEFT 2
#define LED_RIGHT 1

void motor(short left, short right)
{
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
	motor(0,0);
}

void forward(int mm) {
	motor(LEFT_POWER, RIGHT_POWER);
	Wait(MM * mm);
	stop();
}

void turn_right(void) {
	motor(LEFT_POWER, -RIGHT_POWER);
	Wait(NN * 30);
	stop();
}

void turn_left(void) {
	motor(-LEFT_POWER, RIGHT_POWER);
	Wait(NN * 30);
	stop();
}

void step(int n) {
	forward(n); // forward n[mm]
	stop();
}

int is_black_left(void) {
	return ADRead(LEFT_EYE) > BLACK;//左目のセンサーが黒閾値以上だったら真
}

int is_black_right(void) {
	return ADRead(RIGHT_EYE) > BLACK;//右目のセンサーが黒閾値以上だったら真
}

int is_black(void) {
	return (is_black_left() == 1 || is_black_right() == 1); // 左右どちらかが黒なら真,両方が白なら偽
}

void black_count(void){
	int black_count;
	black_count += 1;
	if(black_count > 10){
		stop();
		break;
	}else if(black_count >=5){
		;
	}else{
		;
	}
}

void buzzer(void){
    BuzzerSet(120, 100);
    BuzzerStart();
    Wait(400);
    BuzzerStop();
    Wait(100);
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int black_count = 0;

	Wait(1000);
	for(;;){
		if((is_black_left() == 0) && (is_black_right() == 0)){
			step(10);
			buzzer();
			Wait(5000);
		}else if(is_black_left() && is_black_right()){
			black_count();
		}else if((is_black_left() == 1) && (is_black_right() == 0)){
            turn_left();
            LED(2);
        }else if((is_black_left() == 0) && (is_black_right() == 1)){
        	turn_right();
        	LED(1);
        }else{
			;
		}
		stop();
		return 0;
	}

	stop();
	return 0;
}
