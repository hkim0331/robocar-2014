#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT_EYE    0
#define RIGHT_EYE   1
#define BLACK 500
#define GRAY 400

void stop(void) {
    motor(0,0);
}

void forward(int mm) {
    motor(LEFT_POWER, RIGHT_POWER);
    Wait(MM * mm);
    stop();
}

void step(void) {
    forward(5); /
    stop();
}
int is_black_left(void) {
    return ADRead(LEFT_EYE) > BLACK;

int is_black_right(void) {
    return ADRead(RIGHT_EYE) > BLACK;
}

int is_black(void) {
    return (is_black_left() || is_black_right());
}

int turnL(void){
	motor(0,RIGHT_POWER);
	Wait(100);
}

int turnR(void){
	motor(LEFT_POWER,0);
	Wait(100);
}

int is_gray_left(void){
	return ADread(LEFT_EYE)>GRAY;
}

int is_gray_right(void){
	return ADread(RIGHT_EYE)>GRAY;
}

int is_gray(void){
	return(is_gray_left||is_gray_right);
}

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){
		forward();
		Wait(500);

		if(is_black()){
			stop();
		}
		else if(is_black_left()){
			turnR();
		}
		else if(is_black_right()){
			turnL();
		}
		else if(is_gray){
			 motor(LEFT_POWER/2,RIGHT_POWER/2);

		}





		}


	}



	return 0;


}

