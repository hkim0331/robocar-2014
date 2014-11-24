## 長さを測れ

<div>
  <img src="images/length.png" style='width:60%;'>
</div>

黒エリアの長さを求めたい。
左下から右上への黒線に乗ってロボカーを動かすのだが、

1. 最初の短い本黒線は踏み越し、
2. 真ん中の長い黒エリアの中を前進、
3. 右上の黒エリアの向こう側エッジ（白白）で停止したい。

授業は聞いてるだけじゃダメ。考えてっか？
クリックして
<a href="ideas.cgi">自分の考えを述べよ</a>。

##　step を応用する

ロボカーの動作を 「5mm ずつステップ」に戻す。

````c
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT	1
#define RIGHT	0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20 		// 1mm 進むための時間
#define BLACK 500 	// 白黒判断の境界値

void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
	motor(0,0);
}

void forward(int mm) {
	LED(LED_LEFT + LED_RIGHT);
	motor(LEFT_POWER, RIGHT_POWER);
	Wait(MM * mm);
	stop();
}

void turn(uint8_t dir) {
	if (dir == LEFT) {
		LED(LED_LEFT);
		motor(LEFT_POWER/3,RIGHT_POWER);
	} else if (dir == RIGHT) {
		LED(LED_RIGHT);
		motor(LEFT_POWER,RIGHT_POWER/3);
	}
}

void step(int n) {
	forward(n); // forward nmm
	stop();
}

int is_black(uint8_t n) {
	return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
	return ! is_black(n);
}

int main(void) {
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			step(5);
			Wait(500); // この Wait() は動作が完成したら削ろう。
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			; // このときどうするか？
		} else if (is_black(LEFT)) {
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			turn(RIGHT);
		} else {
			; // 安全のための else
		}
	}
	stop();
	return 0;
}
````

### 問題
プログラムは良さげで良くない。
黒線をはさんでステップしていて、黒黒になった状況でロボカーがどんな動作をするか、予測し、説明しなさい。

## 黒線の長さを測る

整数型の変数 blacks を準備し、5mm 進むごとに連続何回、黒黒をカウントするかを数えよう。
黒テープの幅は 18mm。４つ以上黒黒が続いたら「長い黒」だ。

````c
	...
	else if (is_black(LEFT) && is_black(RIGHT)) {
			blacks += 1;
			step();
			if (blacks > 20) {
				stop();
				break;
			} else if (blacks >= 4) {
				; // ライントレースの方法を変えねば。白黒、黒白の時に曲がる方向が逆だ。
			}
		}
	}
	...
````

### 初期化は重要

変数の名前はかなり自由に付けられる。
しかし、意味のある変数名を選ばないとあとでプログラムの内容がわからなくなる。

````c
int blacks;
````

さて、上の変数 blacks の値はいくらでしょう？　正解は「決まってない」です。
多くの初心者が「ゼロになる」と思い込んで痛い目にあっています。

黒黒が連続する回数を数えたいんだから、ループに入る前と、黒黒以外になったとき、変数 blacks は 0 にリセットしないといけない。さて、それはどこか？正解をグループ内で確認すること。

## 黒枠内を進むには

プログラム中、コメントで書いたが、ライントレースしているときと、黒枠中を進むときは、
白黒、黒白を見たときに曲がる方向が違う。ちゃんとプログラムしないとな。

## 音で知らせる問題
踏み越した黒の長さをブザーで知らせろ。１cmはプッ、３cmはプップップッのように。

## 模様を測定する --- 配列が利用できれば
ロボカーを一定の時間（あるいは黒３cmエリアまで）動かす。
動作開始後、停止するまでのグラウンドの状況を音で報告させろ。
配列に step ごとの白黒を記録し、動作完了したら配列に記録されたデータに従って音出しすればいい。

## ステップをあえてやめる
ステップすれば黒線長さを測るのは比較的楽。ステップやめても長さを測れるようにせよ。

##
written by hkimura.
