#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define N 10

void beep(int length) {
    Wait(1000);
	BuzzerSet(100,100);
	BuzzerStart();
	Wait(length );
	BuzzerStop();
	Wait(100);

int average(int a[],int from, int to){
		int ret=0;
		int i;
		for(i=from; i<to; i++){
			ret += a[i];

			return ret;
		}
	}
void color(int n );
     int c[n];
     int i;

    for (i=0; i<n; i++);
    c[n]=ADRead(0);
    Wait(1000);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    Wait (1000);

    int c;
    int h;
    int d;

    while(1){
    	Wait(1000)
        LED(3)
    }


    while ()


	return 0;
}

