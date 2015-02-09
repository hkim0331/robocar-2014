#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define MAX 10
#define VOL 100

void buzzer(int time){
	BuzzerSet(160, VOL);
	BuzzerStart();
	Wait(time);
	BuzzerStop();
	Wait(time);
}
void beep(int color){
	int i;
	for(i=0;i<(color/100);i++){
		buzzer(400);
	}
	Wait(1000);
	for(i=0;i<((color-100*(color/100))/10);i++){
		buzzer(200);
	}
}
int ave(int *color){
	int i;
	int sum=0;
	for(i=0;i<MAX;i++){
		sum+=color[i];
	}
	return sum/MAX;
}
int main(void)
{
	int color[MAX];
	int i;
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	for(i=0;i<MAX;i++){
		color[i]=ADRead(1);
	}
	beep(ave(color));
	return 0;
}


//黒７２０、グレー５００、緑３００、青５０、黄色５０、赤４０、白４０
