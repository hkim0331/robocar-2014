#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

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

void beep1(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(500);
  BuzzerStop();
  Wait(500);
}

void beep2(void){
	BuzzerSet(100,100);
	  BuzzerStart();
	  Wait(100);
	  BuzzerStop();
	  Wait(100);
}

void led(void){
	LED(3);
	Wait(100);

}

void color(void) {
  int i;
  int n=average();
  int c=n/100;
  int h=n%10;

  for (i=0; i<c; i++) {
    beep1();
    for(i=0;i<h;i++){
    	beep2();
    }
  }
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(100);
	led();
    color();

	return 0;
}

