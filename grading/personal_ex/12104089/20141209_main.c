#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define black1 700
#define black2 1023
#define white1 0
#define white2 300

unsigned short left;
unsigned short right;

void white(){
	(white1<left)&&(left<white2)&&(white1<right)&&(right<white2);
}
void black(){
	(black1<left)&&(left<black2)&&(black1<right)&&(right<black2);
}
void gray(){
	(white2<left)&&(left<black1)&&(white2<right)&&(right<black1);
}
void stop(){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
void start(){
	for(;;){
    Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
}}
void tright(){
    Mtr_Run_lv(0, -10000, 0, 0, 0, 0);
}
void tleft(){
	Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
}
void slow(){
    Mtr_Run_lv(5000, -5000, 0, 0, 0, 0);
}
void run(){
	left = ADRead(0);
	right = ADRead(1);

	if(white()){
		start();
	}else if(gray()){
		slow();
	}else if(black()){



	}

}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	run();

	return 0;
}

