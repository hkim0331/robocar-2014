#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define N 10

void sound(time) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(time);
  BuzzerStop();
  Wait(100);
}

int average(int x[],int from,int to) {
  int ret=0;;
  int i;

  for (i=from;i<to;i) {
    ret += x[i];
  }
  return ret/(to-from);
}

int color(int n){
	int b[n];
	int i;

for (i=0; i<n; i++){
     b[i]=ADRead(0);
     Wait(200);
}
	return average(b,0,n);


}
int light(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int c;
	int a;
	int e;

  while(1){
     Wait(1000);
     LED(3);
     c = color(N);
	 a = c/100;
     e = c%10;
     while (a>0){
     sound(500);
     a--;
     }
	 while (e>0){
	  sound(100);
     e--;
  }
     LED(0);

  }




}

int main(){
const unsigned short MainCycle = 60;
	Init(MainCycle);

	light();

	return 0;
}

