#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


unsigned short left,right;
int i,h;

int ww()
{
	Mtr_Run_lv(10000,-9000,0,0,0,0);
	Wait(50);
	Mtr_Run_lv(0,0,0,0,0,0);

}
int bb()
{
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}
int bw(){
	Mtr_Run_lv(9000,9000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	ww();
}
int wb()
{
	Mtr_Run_lv(-11000,-9000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	ww();
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	for1();
}

int for1(){
	for( ; ; ) {
		ww();
		Wait(50);
		left=ADRead(0);
		right=ADRead(1);
		if(400<left){break;
		}
		else if(500<right){break;
		}
		else if(500<right && 500<left){break;
		}
		else{;}
	}
	if(500<right && 500<left){

		for(h=0;h<4;h++){
			Wait(50);
			Mtr_Run_lv(10000,-9000,0,0,0,0);
			Wait(100);
			Mtr_Run_lv(0,0,0,0,0,0);

			LED(3);
			Wait(100);
			for (h=0; h<4; h++) {
				LED((i%2)+1);
			}
			for2();
		}
	}
	else if(500<right && 500>left){
		wb();
	}
	else if(500<left && 500>right){
		bw();
	}
	else{;}

	return 0;
}
int for2(){
	for( ; ; ) {
		ww();
		Wait(50);
		left=ADRead(0);
		right=ADRead(1);
		if(400<left){break;
		}
		else if(500<right){break;
		}
		else if(500<right && 500<left){break;
		}
		else{;}
	}
	if(500<right && 500<left){

		for(h=0;h<26;h++){
			Wait(50);
			Mtr_Run_lv(10000,-9000,0,0,0,0);
			Wait(100);
			Mtr_Run_lv(0,0,0,0,0,0);
			LED(3);
			Wait(100);
			for (h=0; h<26; h++) {
				LED((i%2)+1);
			}
			for3();
		}
	}
	else if(500<right && 500>left){
		wb();
	}
	else if(500<left && 500>right){
		bw();
	}
	else{;}

	return 0;
}
int for3(){
	for( ; ; ) {
		ww();
		Wait(50);
		left=ADRead(0);
		right=ADRead(1);
		if(400<left){break;
		}
		else if(500<right){break;
		}
		else if(500<right && 500<left){break;
		}
		else{;}
	}
	if(500<right && 500<left){

		for(h=0;h<15;h++){
			Wait(50);
			Mtr_Run_lv(10000,-9000,0,0,0,0);
			Wait(100);
			Mtr_Run_lv(0,0,0,0,0,0);
			LED(3);
			Wait(100);
			for (h=0; h<15; h++) {
				LED((i%2)+1);
			}
			bb();
		}
	}
	else if(500<right && 500>left){
		wb();
	}
	else if(500<left && 500>right){
		bw();
	}
	else{;}
	return 0;
}



