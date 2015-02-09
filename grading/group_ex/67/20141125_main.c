#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define POWER(L)  10000
#define POWER(R) 10000
#define LEFT    1
#define RIGHT   0

#define LED(L) 2
#define LED(R) 1

#define MM 20
#define BLACK 500

void motor(short left, short right) {
    Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
    motor(0,0);
}

void forward(int mm) {
    LED(LED(L) + LED(R));
    motor(POWER(L), POWER(R));
    Wait(MM * mm);
    stop();
}

void turn(int8_t dir) {
    if (dir == LEFT) {
        LED(LED(L));
        motor(POWER(L)/3,POWER(R));
    } else if (dir == RIGHT) {
        LED(LED(R));
        motor(POWER(L),POWER(R)/3);
    }
}

void step(int n) {
    forward(n);
    stop();
}

int black(int8_t n) {
    return ADRead(n) > BLACK;
}

int white(int8_t n) {
    return ! black(n);
}


int buzzer(void){
	BuzzerSet(179,100);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
	Wait(100);
}

int main(void) {
    const unsigned short MainCycle = 60;
    Init(MainCycle);

    int blacks = 0 ;
    int i=0;
    Wait(1000);
    for (;;) {
        if (white(LEFT) && white(RIGHT)) {
        	if(blacks>2 && blacks<6){
        		while(i<blacks){
        			buzzer();
        			i++;
        		}
        		stop();
        		break;
        	}
        	else {
        		blacks=0;
        	}
            step(5);
            Wait(500);
            blacks=0;

        } else if (black(LEFT) && black(RIGHT)) {
        	blacks += 1;
        	step(5);
        	Wait(100);

        } else if (black(LEFT)) {
            turn(LEFT);
            blacks=0;
        } else if (black(RIGHT)) {
            turn(RIGHT);
            blacks=0;
        } else {

            ;
        }
    }
    stop();
    return 0;
}
