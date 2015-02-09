
#define DO    179
#define RE    160
#define MI    142
#define FA    134
#define SO    120
#define RA    107
#define SI    95
#define XX    0


#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void led(int n){

	LED(n);
    Wait(1000);

}

void play(int pitch,int t){

	if(pitch==0){
		Wait(t);
	}
	else{
	 BuzzerSet(pitch,100);
	 BuzzerStart();
	 Wait(t);
	 BuzzerStop();
	}

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	led(3);

	int i,x;

	for (i=0; i<100; i++) {
	        led((i%2)+1);
	        if((i%2)+1==1){x=SI;}
	        else if((i%2)+1==2){x=SO;}
	        else{x=XX;}
	        play(x,1000);
    }

	led(0);


	return 0;
}

