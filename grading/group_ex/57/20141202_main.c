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

void color1(void) {
  int i;
  int n=average();

  LED(1);

  for (i=0; i<n; i+=3) {
    beep();
  }
}

void color2(void) {
  int i;
  int n=average();

  LED(2);

  for (i=0; i<n; i+=40) {
    beep();
  }
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	if(average()<100){
	color1();
	}else{
    color2();
	}

	return 0;
}
//黄：51、赤：54、青：57、緑：120、グレー：240、黒：840
