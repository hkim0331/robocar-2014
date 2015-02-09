#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define R 20000		//右モーター出力バランス
#define L 20000		//左モーター出力バランス
#define black 600		//黒色認識基準
void run(short a,short b){	//コード簡略化用関数
	Mtr_Run_lv(a,-b,0,0,0,0);
}
void foward(void){	//前進プログラム
	run(R,L);
}
void right(void){		//右折プログラム
	run(-R*0.5,L);
}
void left(void){		//左折プログラム
	run(R,-L*0.5);
}
void stop(void){		//停止プログラム
	run(0,0);
}
int test(void){		//センサー特性テストプログラム
	unsigned char a;
	while(1){
		a=(ADRead(0)>black)+(ADRead(1)>black)*2;
		LED(a);
	}
}
int read(void){		//センサー読み取り
	unsigned char a;
	a=(ADRead(0)>black)+(ADRead(1)>black)*2;
	return a;		//センサー対応値出力
}
void turn(void){		//走行プログラム
	int c=0;
	while(c!=3){
		c=read();		//センサー値取り込み
		switch(c){
			case 0:
				foward();
				LED(3);
				break;
			case 1:
				left();
				LED(2);
				break;
			case 2:
				right();
				LED(1);
				break;
			case 3:
				stop();
				LED(0);
				break;
		}
	}
}
void wake_up(void){		//電源投入確認
	int i;
	for(i=0;i<5;i++){
		LED(3);
		Wait(250);
		LED(0);
		Wait(250);
	}
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	wake_up();
	turn();
	return 0;
}
