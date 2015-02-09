#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define pitch 100
#define VOL 100
#define wait1 1000
#define wait2 100
#define PAUSE1 300
#define PAUSE2 100

int count(int i,int j){
	return (i / j);
}

void beep(int n) {
	BuzzerSet(pitch,VOL);
	BuzzerStart();
	Wait(n);
	BuzzerStop();
	Wait(n);
}

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
		Wait(wait2);
	}
	return sum(x,0,5)/5;
}

void color(void) {
	int i, c1, c2;
	int n=average();

	c1 = count(n, 100);
	c2 = count(n - (100*c1), 10);

	for(i=0; i<c1; i++){
		beep(PAUSE1);
	}
	for(i=0; i<c2; i++){
		beep(PAUSE2);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(wait1);

	color();

	return 0;
}

/*緑...190
  黄...60
  青...80
  グレー...580
  赤...60
  黒...920

  黄 <= 赤 < 青 < 緑 < グレー < 黒
 */



