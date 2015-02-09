#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep1(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
 }


void beep2(void) {
  BuzzerSet(140,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
 }

int sum(int a[], int from, int to) {
 int ret=0;
 int i;

 for (i=from; i<to; i++) {
  ret += a[i];
  }
 return ret;
 }

int average(){
 int x[10];
 int i;

 for (i=0;i<10;i++) {
  x[i] = ADRead(0);
  Wait(100);
  }
 return sum(x,0,10)/10;
 }

void color() {
  int i;
  int n=average();
 if(n>100){
  for (i=0; i<n; i+=100) {
   beep1();
   Wait(100);
  }
 }else{
  for (i=0; i<n; i+=1) {
   beep2();
   Wait(100);
  }
 }
 }

int main(void)
{
 const unsigned short MainCycle = 60;
 Init(MainCycle);

 color();
 return 0;
}

//白、赤、黄、青、緑、グレー、黒
