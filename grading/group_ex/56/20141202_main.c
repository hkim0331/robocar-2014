#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(300);
}

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
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,n)/n;
}

int main(void){
    const unsigned short MainCycle = 60;
    Init(MainCycle);
    int i;
    int v=average(20);
    if(v<200){
     for (i=60; i<v; i+=1) {
      beep();
     }
    }
    else{
    	LED(1);
    	for (i=0; i<v; i+=50) {
    	      beep();
    	     }
    }
}
//黒850　グレー550　緑300　青72　黄67　赤63 白61
