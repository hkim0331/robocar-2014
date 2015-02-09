#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}
void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

int average(int a[],int from,int to) {
    int ret=0;
    int i;

 for(i=from;i<to;i++){
      ret +=a[i];
 return ret/(to-from);
 }
}
int color(int a) {
  int i;
  int n=average();{

  for (i=0; i<n; i++)
    beep();

  }
}
int color(int n)                                                               )
    int c[n];
    int i;
    for(i=0;i<n;i++){
    	c[i]=ADRead(0);
    	Wait(100);
    	}
    return average(c,0,n);
    }
 int main(void)
 {
	 const unsigned short MainCycle=60;
	 Init(MainCycle);

	 int c;
	 int h;
	 int d;

	 while (1){
		  Wait(1000);
		  LED(3);
		  c=color(N);
		  h=c/100;
		  d=c%10;
		  while(h>0){
			  beep(500);
			  h-;
		  }
		  while(d>0){
		  }
	 }
 }
