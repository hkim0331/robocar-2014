#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(200);
}

void beep1(void) {
  BuzzerSet(150,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(200);
}

void beep2(void) {
  BuzzerSet(200,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(200);
}


int sum(int a[], int from, int to) {
  int ret=0;
  int i;

  for (i=from; i<to; i++) {
    ret += a[i];
  }
  return ret;
}

int average(void) {
  int x[5];
  int i;

  for (i=0;i<5;i++) {
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,5)/5;
}

void color(void) {
  int i;
  int n=average();

  for (i=0; i<n; i+=100) {
    beep();
  }
}

void color1(void) {
  int i;
  int n=average();
  int a;

  a = n%100;
  for (i=0; i<a; i+=10) {
    beep1();
  }
}

void color2(void) {
  int i;
  int n=average();
  int b;
  int c;

  b = n%100;
  c = b%10;

  for (i=0; i<c; i+=1) {
    beep2();
  }
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    color();
    color1();
    color2();
	return 0;
	//white 160
	//red   161
	//yellow162
	//blue  164
	//green 275
	//gray  515
	//black 993
}

