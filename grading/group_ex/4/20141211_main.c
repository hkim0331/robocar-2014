#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void buzzer(int jikan){
	BuzzerSet(100,30);
	BuzzerStart();
	Wait(jikan);
	BuzzerStop();
	Wait(100);
}                            //jikanでブザーのなる時間設定

int sum(int a[], int from, int to){
	int ret=0;
	int i;
	for(i=from; i<to; i++){
		ret += a[i];
	}
	return ret/(to-from);
}                            //aという配列の合計を平均出す

int color(void){
	int x[5];
	int i;

	for(i=0; i<5; i++) {
		x[i] = ADRead(0);
		Wait(100);
	}
	return sum(x,0,5)/5;
}                                          //センサで5回読み込んだADReadの値の平均を出す


int main(void) {

    const unsigned short MainCycle = 60;
    Init(MainCycle);

    while(1){

    int i;
    int n = color();
    int hyaku = n/100;  //カラーの百の位
    int ju = n%100; //カラーの十の位

	Wait(1000);
	LED(3);
	for (i=0; i<hyaku; i++) {          //0～hyakuまで1刻みでブザー鳴らす
	    buzzer(500);
	  }
	for(i=0; i<ju; i+=10){              //0～juまで10刻みでブザー鳴らす
		buzzer(250);
	}
	LED(0);
    }

    return 0;
}

