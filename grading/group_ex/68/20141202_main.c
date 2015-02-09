#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

int sum(int a[],int from,int to) {
  int ret=0;
  int i;

  for(i=from ; i<to ; i++){
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

void color(void) {
  int i;
  int n=average(5);

  for (i=0 ; i<n ; i += 100) {
     beep();
  }

  Wait(1000);

  for(i=0 ; i<(n%100) ; i+= 10){
	  beep();
  }

  Wait(1000);

  for(i=0 ; i<(n%10) ; i++){
	  beep();
}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}

//赤色　２３３
//黄色　２４６
//白色　２５６
//青色　２６６
//緑色　５４３
//灰色　５７３
//黒色　１０２７
