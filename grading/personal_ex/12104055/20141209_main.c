#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


#define W 22
#define A 21
#define S 11
#define D 12
#define sW 33
#define sA 31
#define sD 13
#define ST 40
#define GL 50 //緑
#define OL 60 //オレンジ
#define NL 70 //消灯

#define XX -1


void robocarmtr(int hidari,int migi,int zikan)
{
	  Mtr_Run_lv(hidari,migi, 0, 0, 0, 0); //(左,右，無効,無効,無効,無効)
	  Wait(zikan);
}

void robocarstop(void){
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}


void chokushin(int zikan)
{
	robocarmtr(10000,-10000,zikan)	;
}

void teisoku(int zikan)
{
	robocarmtr(5000,-5000,zikan)	;
}

void koushin(int zikan)
{
	robocarmtr(-10000,10000,zikan)	;
}

void hidarishin(int zikan)
{

	robocarmtr(3000,-10000,zikan)	;
}

void migishin(int zikan)
{

	robocarmtr(10000,-3000,zikan)	;
}

void hidaricho(int zikan)
{

	robocarmtr(-10000,-10000,zikan)	;
}

void migicho(int zikan)
{
	robocarmtr(10000,10000,zikan)	;
}

void ledtentou(int iro,int zikan)
{
	LED(iro);
	Wait(zikan);
}



void move(int houkou,int nagasa)
{


	if(houkou == W){
		chokushin(nagasa);
		}
	else if(houkou == A){
		koushin(nagasa);
		}
	else if(houkou == S){
		hidaricho(nagasa);
		}
	else if(houkou == D){
		migicho(nagasa);
		}
	else if(houkou == sW){
		teisoku(nagasa);
		}
	else if(houkou == sA){
		hidarishin(nagasa);
		}
	else if(houkou == sD){
		migishin(nagasa);
		}
	else if(houkou == GL){
		ledtentou(1,nagasa);
		}
	else if(houkou == OL){
		ledtentou(2,nagasa);
		}
	else if(houkou == NL){
		ledtentou(0,nagasa);
		}
	else if(houkou == ST){
		robocarstop();
		Wait(nagasa);
		}
	else {
		robocarstop();
		}

}

void junkou(void){


	unsigned short migi,hidari;


	while(1){

		migi = ADRead(0);
		hidari = ADRead(1);



		if (migi>300 || hidari >300){

			if(migi>300 && hidari >300){
				break;
				}else{
				;
				}


			if(migi>300){
				move(sD,100);

				}else{
				move(sA,100);

				}

			}else{
				move(W,100);

			}
		}




}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short migi,hidari;


	while(1){

		migi = ADRead(0);
		hidari = ADRead(1);

		Wait(100);

		if(migi>300 && hidari >300){
				break;
				}

			}

	move(OL,1000);
	move(GL,1000);
	move(OL,1000);


	S1();
	S2();
	S3();


	return 0;
}

void S1(void){
	move(W,200);
	move(GL,0);
	junkou();

}

void S2(void){
	move(W,200);
	move(OL,0);
	junkou();

}

void S3(void){
	move(GL,0);
	robocarstop();

}
