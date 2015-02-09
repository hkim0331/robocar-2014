#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define LIGHT 10200
#define LEFT 10000
#define EDGE 1
#define FW 80

//unsigned int ADRead(unsigned char n);


void motor(short light, short left){
	Mtr_Run_lv(light,-left,0,0,0,0);
}

void stop(void){
	motor(0,0);
	Wait(200);
}

void step(int n){
	motor(LIGHT,LEFT);
	Wait(FW*n);
	stop();

}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short x;
    int i;
    for(i=0;i<10;i++){
    	step(EDGE);
    	stop();
    	x=ADRead(1);
    	if (x>500){
    		break;
    	}else{
    		;
    	}
    }
    BuzzerSet(179,100);
    BuzzerStart();
    Wait(750);
    BuzzerStop();

	return 0;
}

