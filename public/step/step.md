## step/src/main.c

hkimura の解答例。このままコピーしても動かない。

````
if (you_are_boke?) {
  要領よく理解せずにコピーして終わりと思うな;
  「要領がいい」とは「サイテーの男」の意味;
  こんな奴につかまるとロクでもないぞ;
} else {
  プログラムに書かれた内容を理解しようと努めろ;
  そうすればいつかは道は開ける;
}
````

ここから。

````c
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*
関数 kaeru() 引用省略、該当ページを参照せよ。
*/

#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT_EYE	0
#define RIGHT_EYE	1

#define MM 20 //5mm 進むための時間
#define BLACK 500 // 白黒判断の境界値

/*
関数 motor() 隠蔽、ボケがコピーで満足しないように。
*/

void stop(void) {
	motor(0,0);
}

void forward(int mm) {
	motor(LEFT_POWER, RIGHT_POWER);
	Wait(MM * mm);
	stop();
}

void step(void) {
	forward(5); // forward 5mm
	stop();
}

int is_black_left(void) {
	return ADRead(LEFT_EYE) > BLACK;　//左目のセンサーが黒閾値以上だったら真
}

int is_black_right(void) {
	return ADRead(RIGHT_EYE) > BLACK;//右目のセンサーが黒閾値以上だったら真
}

int is_black(void) {
	return (is_black_left() || is_black_right()); // 左または右が黒だったら真
	// 外側のかっこはなくてもコンピュータが理解する意味は変わらない。
	// でも、人間はどうだろう？
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for (;;) {
		step();
		Wait(500);
		if (is_black()) { // 変数に代入せず、直接、関数の戻り値で判断。
			break;
		} else {
			;
		}
	}
	kaeru();

	return 0;
}
````

[back](index.html)
----
programmed by hkimura.
