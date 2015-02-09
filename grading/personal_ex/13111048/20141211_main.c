#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


int buzzer(int L){
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}

int average(int a[],int from,int to){
	int ret = 0;
	int i;
	for(i=from;i<to;i++){
		ret+=a[i];
		Wait(100);
		ave=sum(c[i],from,to)/5;
	}
	return ret;
}

int color(int n){
	int c[5];
	int i;
	for(i=0;i<5;i++){
		c[i]=ADRead(0);
		Wait(100);
	}
	return ave;
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	buzzer(1000);
	Wait(100);
	LED(3);
	color(10);

	int h;
	int c;

	h=c[i]/100;
	c=c[i]%10;
	while(1){
	buzzer(0);
	Wait();
	if(h>0){
		buzzer(i);
		Wait(1000);
	}
	}

	return 0;
}

