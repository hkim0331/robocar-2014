#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 10000
#define RIGHT 10000

#define LEFTL 1000
#define RIGHTR 1000

#define MM 20     // 1mm 進むための時間
#define BLACK 600

#define LEFTEYE 0
#define RIGHTEYE 1

#define DO 179


void motor(short left, short right) {
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
  motor(0,0);
}

void forward(int mm) {
  motor(LEFT, RIGHT);
  Wait(MM * mm);
}

void right(int mm) {
	motor(LEFT, RIGHTR);
	Wait(MM * mm);
}

void left(int mm) {
	motor(LEFTL, RIGHT);
	Wait(MM * mm);
}

void sla(void) {
  forward(5); // forward 5mm   forward kannsuu ni 5 nyuuryoku    // sonogo stop
}


void slar(void) {
	right(5);
}

void slal(void) {
	left(5);
}

void sla3(void) {
	forward(30);
}




int blackleft(void) {
  return ADRead(LEFTEYE) > BLACK;
}

int blackright(void) {
  return ADRead(RIGHTEYE) > BLACK;
}

int blackall(void) {
  return (blackleft() || blackright());
}




void s1(void) {
	Wait(500);
	for( ; ; ) {
		sla();
		if (blackall()) {
			stop();
		}else if (blackleft()) {
			slar();
		}else if (blackright()) {
			slal();
		}

	}
}

void s2(void) {
	sla3();
	for( ; ; ) {
		sla();
		if (blackall()) {
			stop();
		}else if (blackleft()) {
			slar();
		}else if (blackright()) {
			slal();
		}

		}
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	s2();
	return 0;
}

