#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void play(int x,int y,int t){
 Mtr_Run_lv(x,y,0,0,0,0);
 Wait(t);
 Mtr_Run_lv(0,0,0,0,0,0);
}

void stop(){
	play(0,0,100);
}

void front(){
	play(10000,-10000,50);
}
void left(){
	play(10000,0,50);
}
void right(){
	play(0,-10000,50);
}
void sound(){
    BuzzerSet(120,100);
    BuzzerStart();
    Wait(1000);
    BuzzerStop();
    Wait(2000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i;
	for(i=0;i<100000000;i++){
    if((ADRead(1)<500)&&(ADRead(0)<500)){
     front();
    }else if((ADRead(1)>500)&&(ADRead(0)>500)){
	stop();
    sound();
	break;
	}else if(ADRead(1)>500){
	right();
	}else if(ADRead(0)>500){
	left();
	}
}

	return 0;
}

