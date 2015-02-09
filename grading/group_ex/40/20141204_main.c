// 走行速度:v=11cm/s (R=10000 L=10000)
// 長いエリア:11cm スタートライン:2cm 終端:7cm
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define R 10000	//右モーター出力バランス
#define L 10000	//左モーター出力バランス
#define TIME 91	//TIME=v^(-1)[ms/cm]
#define BLACK 600	//センサー感度
#define SHORT 4
#define LONG 9	//停止範囲

void run(short a,short b){	//コード簡略用関数
	Mtr_Run_lv(a,-b,0,0,0,0);
}

void foward(int t){	//前進プログラム
	run(R,L);
	Wait(t);
}

void stop(int t){	//停止プログラム
	run(0,0);
	Wait(t);
}

void step(void){	//断続走行プログラム
	foward(TIME);
	stop(100);
}

void right(void){		//右折プログラム
	run(-R,L);
}

void left(void){		//左折プログラム
	run(R,-L);
}

void wake_up(void){		//電源投入確認プログラム
	int i;
	for(i=0;i<5;i++){
		LED(3);
		Wait(250);
		LED(0);
		Wait(250);
	}
}

void test(void){	//モーター特性テスト
	step();
	stop(0);
}

int read(void){		//センサー読み取り
	unsigned char a;
	a=(ADRead(0)>BLACK)+(ADRead(1)>BLACK)*2;
	return a;		//センサー対応値出力
}

void sound(int n){		//音声出力プログラム
	BuzzerSet(120,100);
	BuzzerStart();
	Wait(n);
	BuzzerStop();
	Wait(500);
}

void output(int x){	//測定結果出力プロフラム
	int a;
	int b;

	a=x/5;
	b=x%5;

	int i;
	for(i=0;i<a;i++){
		sound(1000);
	}
	for(i=0;i<b;i++){
		sound(500);
	}
}

void length(void){
	int s;
	int l=0;
	char end=1;

	while(end){
		s=read();
		switch(s){
			case 0:
				if(l>SHORT&&l<LONG){
					stop(0);
					output(l);
					end=0;
				}else{
					stop(0);
					output(l);
					step();
				}
				l=0;
				break;

			case 1:
				left();
				break;

			case 2:
				right();
				break;

			case 3:
				step();
				l++;
				break;
		}
	}
}
int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	wake_up();
	length();
	return 0;
}
