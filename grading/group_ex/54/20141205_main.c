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

int average(int n) {
  int x[n];
  int i;

  for (i=0;i<n;i++) {
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,n)/n;
  }

void beep(int d) {
  BuzzerSet(d,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

void color(void) {
  int i,j,k;
  int count=0;
  int x=0;
  int n=average(5);

  for (i=0; i<n; i+=100) {
    beep(179);
    count += 100;
    LED(1);
  }//100の位を鳴らす（4桁の場合1000の位）
  LED(0);
  Wait(1000);

  int n1=n-count+100;

  for(j=0; j<n1; j+= 10){
	  beep(142);
	  x += 10;
	  LED(2);
  }//10の位を鳴らす（4桁の場合100の位）

  LED(0);
  Wait(1000);

  int n2=n1-x+10;

  for(k=0; k<n2 ;k+=1){
	  beep(120);
	  LED(3);
  }//1の位を鳴らす（4桁の場合10の位）
  LED(0);

  /*int n3=n2

  for(l=0; l<n3 ;l++){
	  beep(107);
	  LED(1);
  }

  LED(0);*/
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}

//白　赤　黄　青　緑423　灰677　黒

