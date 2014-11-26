#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT 20000 //左モータの出力量
#define RIGHT -20000 //右モーターの出力量
#define TIME 50    //~ミリ進む時間


void motor(short left, short right){
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}                                              //モーター基礎

void stop(void){
	motor(0,0);
}                                             //ロボカー停止

void forward(void){
	motor(LEFT, RIGHT);
	Wait(TIME);
	stop();
}                                             //ロボカー前進

void turn_left(void){
	motor(0,-10000);
	Wait(20);
	stop();
}                                            //ロボカー左回転

void turn_right(void){
	motor(10000, 0);
	Wait(20);
	stop();
}                                            //ロボカー右回転

int main(void){
	const unsigned short MainCycle = 60;
	  Init(MainCycle);

	  unsigned short readL;
	  unsigned short readR;

	  for (;;){
		  readL = ADRead(0);
		  readR = ADRead(1);
		  if(readL > 500 && readR > 500){
			  forward();
		  }                                    //右左センサ両方が黒認識ならば前進

		  else if(readL > 500 && readR < 500){
			  turn_left();
		  }                                     //左センサーが黒、右センサーが白認識ならば左回転

		  else if(readL < 500 && readR > 500){
			  turn_right();
		  }                                       //左センサーが白、右センサーが黒認識ならば右回転
		  else {
			  break;
		  }                                       //それ以外ならばループ終了
	  }

	  stop();

	  return 0;

}
