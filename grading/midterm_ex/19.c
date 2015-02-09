#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  10000

#define FW 70
#define N 50

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}
void forward(int n)
{
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}
void right(int m){
	motor(0,RIGHT);
	Wait(FW * m);
	stop();
}
void left(int l){
	motor(LEFT,0);
	Wait(FW * l);
	stop();
}
void step(void){
	forward(5);
	stop();
}

int is_black_left(void){
	return ADRead(0) > 600;
}

int is_black_right(void){
	return ADRead(1) > 600;
}
int is_white_left(void){
	return ADRead(0) < 500;
}

int is_white_right(void){
	return ADRead(1) < 500;
}
int is_black(void){
	return ( is_black_left() || is_black_right() );
}
int is_white(void){
	return( is_white_left() || is_white_right() );
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){
		if (is_white()){
			step();
			LED(3);
			Wait(100);
		}
		if (is_black_right()){
			right(5);
			LED(1);
			Wait(100);
		}
		if (is_black_left()){
			left(5);
			LED(2);
			Wait(100);
		}

		}
	return 0;
}

