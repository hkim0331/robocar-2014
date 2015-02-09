#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DO 179
#define RE 160
#define RA 107
void beep(int s) {
	 BuzzerSet(s,100);
	 BuzzerStart();
	 Wait(100);
	 BuzzerStop();
	 Wait(100);
}
int sum(int a[], int from, int to) {
     int ret = 0;
     int i;

     for(i=from;i<to;i++){
        ret += a[i];
     }
     return ret;
}
int average(int n) {
	int x[n];
	int i;

	for(i=0; i<n; i+=1){
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,n)/n;
}
void color(void){
	int j;
	int n = average(5);
    int m = n%100;     //average下二桁
    int p = m%10;      //average下一桁
	for(j=100;j<n;j+=100){
		beep(RA);
	}
	Wait(1000);
	for(j=10;j<m;j+=10){
		beep(DO);
	}
	Wait(1000);
	for(j=1;j<p;j+=1){
		beep(RE);
	}

}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	color();

	return 0;
}

/*白  50
  黄  51
  赤  52
  水  54
  緑 156
  灰 423
  黒 841*/
