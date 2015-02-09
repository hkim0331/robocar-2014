#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define ADR_TIME 100

#define PITCH 100
#define VOLUME 100
#define SOUND_TIME 100
#define RYTHEM 100

#define LEFT 0
#define LED_LEFT 1
#define LED_RIGHT 2

#define DIGIT_TIME 1000

int sum(int a[], int from, int to) {
  int ret=0;
  int i;

  for (i=from; i<to; i++) {
    ret += a[i];
  }
  return ret;
}

int average(int n) {
  int x[n];
  int i;

  for (i=0;i<n;i++) {
    x[i] = ADRead(LEFT);
    Wait(ADR_TIME);
  }
  return sum(x,0,n)/n;
}

void beep(void) {
  BuzzerSet(PITCH,VOLUME);
  BuzzerStart();
  Wait(SOUND_TIME);
  BuzzerStop();
  Wait(RYTHEM);
}

void color(void) {
  int i;
  int n=average(5);

  for (i=0; i<n/100; i+=1) {
	beep();
    LED(LED_LEFT);
  }
  Wait(DIGIT_TIME);
  for(i=0; i<(n%100)/10; i+=1){
  beep();
  LED(LED_RIGHT);
  }
  Wait(DIGIT_TIME);
  for(i=0; i<(n%100)%10;i+=1){
  beep();
  LED(LED_LEFT + LED_RIGHT);
  }
}

int main(void) {
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  color();

  return 0;
}
//黒734,グレー325,緑131,青56,黄色54,赤53,白52
