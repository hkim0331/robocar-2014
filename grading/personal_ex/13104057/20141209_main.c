#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT_EYE  0
#define RIGHT_EYE 1

#define MM 20
#define BLACK 500

void motor(short left, short right) {
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void slalom(void) {
  if (is_left_white() && is_right_whilte()) {
    go_straight(1);
  } else if (is_left_black()) {
    turn_left();
  } else if (is_right_black()) {
    turn_right();
  } else if (is_left_black() && is_right_is_black()) {

  } else {
    ;
  }
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

