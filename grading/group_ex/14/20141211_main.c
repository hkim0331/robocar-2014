#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void beep(int n) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(n);
  BuzzerStop();
  Wait(100);
}

int average(int a[], int i, int t) {
 int k=0;
for(;i<t;i++){
	k+=a[i];
}


  return (k/t);
}

void color(int x) {
  int i[x];
  int n,c,h;
  int b;
for(b=0;b<100;b++){
	i[b]=ADRead(0);
	Wait(10);
}
 n=average(i,0,100);  //色の平均値　n
 c=n/100;

 h=(n-c*100)/10;


  for (b=0; b<c; b++) {
    beep(500);

  }
  for(b=0;b<h;b++){
	  beep(100);

  }
}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color(100);

	return 0;
}

