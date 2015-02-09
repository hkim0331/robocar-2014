#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER 7500
#define RIGHT_POWER 7500

#define LEFT 0
#define RIGHT 1
#define WHITE 250   // 白の境界値
#define BLACK 500  // 黒の境界値

#define TURN_OFF 0
#define LED_LEFT 1
#define LED_RIGHT 2

#define MM 140  // 5mm進むための時間[ms]
#define STEP 500  // stepで止まる時間[ms]
#define END 0

#define MIN 5  // 止まりたいところでの最小ステップ数
#define MAX 12  // 止まりたいところでの最大ステップ数

#define VOLUME 100
#define RYTHEM 500
#define DO 179
#define NN 0

void motor(short left, short right) {
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void forword(void) {
  LED(LED_LEFT + LED_RIGHT);
  motor(LEFT_POWER, RIGHT_POWER);
}

void step(void) {
  forword();
  motor(0, 0);
}

void stop(unsigned short time) {
  LED(TURN_OFF);
  motor(0, 0);
  Wait(time);
}

void turn(unsigned short direction) {
  if (direction == LEFT) {
	LED(LED_LEFT);
    motor(-LEFT_POWER ,RIGHT_POWER);
  }
  if (direction == RIGHT) {
	LED(LED_RIGHT);
	motor(LEFT_POWER ,-RIGHT_POWER);
  }
}

void play(int pitch){
  if (pitch == NN) {
	BuzzerStop();
    Wait(RYTHEM);
  } else {
    BuzzerSet(pitch, VOLUME);
    BuzzerStart();
    Wait(RYTHEM);
    BuzzerStop();
  }
}

int is_black(unsigned short direction) {
	return ADRead(direction) > BLACK;
  }

int is_white(unsigned short direction) {
  	return ADRead(direction) < WHITE;
  }

int is_gray(unsigned short direction) {
  	return ADRead(direction) > WHITE && ADRead(direction) > BLACK;
  }

int is_long(unsigned short blacks) {
	return blacks;
}

void slalom(void) {
  for (;;) {
    if (is_white(LEFT) && is_white(RIGHT)) {
      forword();
	} else if (is_black(LEFT) && is_black(RIGHT)) {
      stop(END);
      break;
    } else if (is_black(LEFT)) {
      turn(LEFT);
	} else if (is_black(RIGHT)) {
	  turn(RIGHT);
	}
  }
}

void length(void) {
  int grays = 0;

  for (;;) {
    if (grays >= is_long(MIN) && grays <= is_long(MAX) && is_white(LEFT) && is_white(RIGHT)) {
      break;
	} else if (is_gray(LEFT) && is_gray(RIGHT)) {
	  grays += 1;
      step();
      play(DO);
    } else if (is_gray(LEFT)) {
      turn(LEFT);
	} else if (is_gray(RIGHT)) {
	  turn(RIGHT);
	}
  }
}

void dec(void) {
  for (;;) {
    if (is_gray(LEFT) && is_gray(RIGHT)) {
	  length();
    } else {
	  slalom();
    }
  }
}

int main(void) {
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  dec();

  return 0;
}


