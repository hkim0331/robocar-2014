#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT   10000
#define RIGHT  9300

#define LED_LEFT 2
#define LED_RIGHT 1

#define LEFT    1
#define RIGHT   0

#define FW 170

#define N 5

#define TN 8

#define BLACK 500

void motor(short left, short right)
{
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void)
{
  motor(0, 0);
}

void step(int n)
{
  forward(n);
  Wait(500);
}

void forward(int n)
{
  LED(LED_LEFT + LED_RIGHT);
  motor(LEFT, RIGHT);
  Wait(FW * n);
  stop();
}

void turn_left(int deg)
{
  motor(LEFT, 0);
  Wait(TN * deg);
  stop();
}

void turn_right(int deg)
{
  motor(0, RIGHT);
  Wait(TN * deg);
  stop();
}

int is_black_left(void) {
    return ADRead(LEFT_EYE) > BLACK;
}

int is_black_right(void) {
    return ADRead(RIGHT_EYE) > BLACK;
}

int is_black(void) {
    return (is_black_left() || is_black_right());
}

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

	int i=0;

	Wait(1000);

	for(;;)	{
		if (is_white(LEFT) && is_white(RIGHT))	{
			step(1);
			Wait(500);
			if (i==3)	{
				break;
			}
			else {
				i=0;
			}
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			break;
		} else if (is_black(LEFT)) {
			turn_left(20);
		} else if (is_black(RIGHT)) {
			turn_right(20);
		} else {
			;
		}
	}
	stop();
	return 0;
}

