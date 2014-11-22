## 中間テスト回想

教員の回答と自分グループの回答を見比べて一喜一憂するより、
あのオジさんはなにを教えたいのか、汲み取ってくれ。

* ロボカーには個体差がある。それを無視したプログラムではロボカーは思ったようには動いてくれない。
* プログラムは一発では動かない。
何度も修正することを念頭におき、
定数は定数として #define し、共通の内容は一つの関数にまとめる。
結果的に短い時間でプログラムは完成し、他の人にもわかりやすいプログラムとなる。
* 「あとできれいにすればいい」とアドバイス無視で作成したプログラムは、いつまでも汚い。
修正に時間がかかり、あるいは期待通りに動かない。

[回収したテスト](/answers/)

## step をベースに slalom

前々回の授業のテーマは step だった。5mm づつ前進し、黒テープで止まる。これをベースに slalom を考える。

プロジェクト step の main.c は以下のようなものだろう。

````c
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void kaeru(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(1000);
  BuzzerStop();
}

#define LEFT_POWER  10000
#define RIGHT_POWER 10000
#define LEFT_EYE  0
#define RIGHT_EYE 1

#define MM 20     // 1mm 進むための時間
#define BLACK 500   // 白黒判断の境界値

void motor(short left, short right) {
  Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

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
  return ADRead(LEFT_EYE) > BLACK;
}

int is_black_right(void) {
  return ADRead(RIGHT_EYE) > BLACK;
}

int is_black(void) {
  return (is_black_left() || is_black_right());
}

int main(void) {
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  for (;;) {
    step();
    Wait(500);
    if (is_black()) {
      break;
    } else {
      ;
    }
  }
  kaeru();

  return 0;
}
````

### int is_black_left(void) について

関数 is_black_left() は引数を取らず(これが　(void) の意味だ)、
戻り値として int(32 ビットの符号付き整数)を返す。

関数の戻り値は関数のボディ中で最初に実行する return に続く式の値になる。

#### ADRead(LEFT_EYE) > BLACK　の値は？

LEFT_EYE、BLACK の値はプログラムの上の方で #define されている。

ADRead(LEFT_EYE) は unsigned short (0~2^16-1)の値を返す。
それと BLACK との大小を比較する。

ADRead(LEFT_EYE) の戻す値が定数 BLACK よりも大きい時、
ADRead(LEFT_EYE) > BLACK の値は真となる。

この値を return するということは 関数 is_black_left(void) の戻り値が真、ということ。

````c
return (ADRead(LEFT_EYE)>BLACK != 0)
````

あるいは、

````c
return (ADRead(LEFT_EYE)>BLACK == 1)
````

両者同じ意味になるが、0 と比較するだけ無駄っしょ。
なので、ほとんどの C プログラマはこう書く、

````c
return ADRead(LEFT_EYE)>BLACK;
````

## step をどうやって slalom に？

まずは母国語で考える。

「C 言語がわからない」という人は、たいていの場合、
<span style='color:red;'>日本語でもどうしていいかわかってない</span>ことが多い。
分析的に考えられないことを言語に責任を天下するのは無責任ってことじゃないかい。

プログラミング言語を学ぼうって意義のひとつはここ。

どうすれば、黒テープに沿ってロボカーを動かせるか？分析的に考えてみよう。
黒テープの幅はロボットの目となるフォトセンサーの間隔よりちょっと狭いってことが重要だ。

### 第一バージョン（日本語）

````c
もし、黒線をまたいでいたら前進。
右にずれていたら左に曲がる。
左にずれてたら右折。
ゴールについたらカエルの歌。
````

あやふやな部分があるが、これを理解できるのが人間。
しかし、ロボット（コンピュータ）はこのままでは理解できない。
もっと具体的に仕事の内容を書き下してやる必要がある。

### 第２バージョン（半分日本語）

関連するところだけ。

````c
void go-straight(int distance) {
  motor(LEFT,RIGHT);
  Wait(MM * distance); //MMは1mm前進する時間。
}

void slalom(void) {
  if (黒線をまたいでいたら) {
    go_straight(1mm);
  } else if (右にずれたら) {
    turn_left();
  } else if (左にずれたら)　{
    turn_right();
  } else if (ゴールに着いたら) {
  sing(kaeru);
  }
}
````

日本語の部分を、意味を保ったまま、 C 言語に翻訳していこう。

### 黒線をまたいでいたら？を翻訳

同じ意味でも良い方は一つではない。プログラムする人の個性が出る。

以下は一例です。

````c
int is_left_white(void) {
  return ! is_left_black();
}
int is_left_white(void) {
  return ! is_left_black();
}

...
    // 「黒をまたいでいたら」のC表現
    if (is_left_whilte() && is_right_white()) {
        ...
    }
````

###　第３バージョン（だいぶC）

````c
int keru[] = {DO,RE,MI,FA,MI,RE,DO};
void sing(int song[]) {
  play(song);
}

void go-straight(int distance) {
  motor(LEFT,RIGHT);
  Wait(MM * distance); //MMは1mm前進する時間。
}

void slalom(void) {
  if (is_left_white() && is_right_whilte()) {
    go_straight(1);
  } else if (is_left_black()) {
    turn_left();
  } else if (is_right_black()) {
    turn_right();
  } else if (is_left_black() && is_right_is_black()) {
    sing(kaeru);
  } else {
    ;
  }
}
````

これでいけると思う人？　まだマトリックス、見てないね？

### C プログラムの気持ちになって

まだ、ロボカーは期待通りには動かない。
理由はふたつ。

* if は一瞬で通り過ぎる。
* 条件を並べる順番に注意。

````c
while (1==1) {
  if (is_left_white() && is_right_white()) {
    go_straight(1mm);
  } else if (left_is_black() && right_is_black()) {　// ここ
    break;
  } else if (left_is_black()) {
    turn_left();
  } else if (right_is_black()) {
    turn_right();
  } else {
    ;
  }
}
sing(kaeru);

````

while (1==1) は無限ループの表現方法の一つ。1==1 は何回評価しても真。
おなじことを普通の C プログラマは  while (1) や　for (;;) とプログラムしたりする。

if を while で囲み(こっちは納得できる）、判定順番を変えた（それがどうだって？）。
しかし、これはかなりよく効く。説明は授業をよく聞こう。

### if ? それとも if else ?

二つのループを比べる。

````c
while (1) {
  if (is_left_black() && is_right_black()) {
    break;
  } else {
    ;
  }
  if (is_left_whilte() && is_right_white()) {
    go_straight();
  } else {
    ;
  }
  if (is_left_black()) {
    turn_left();
  } else {
    ;
  }
  if (is_right_black()) {
    turn_right();
  } else {
    ;
  }
}
````

````c
while (1) {
  if (is_left_black() && is_right_black()) {
    break;
  } else if (is_left_whilte() && is_right_white()) {
    go_straight();
  } else if (is_left_black()) {
    turn_left();
  } else if (is_right_black()) {
    turn_right();
  } else {
    ;
  }
}
````

* 上のループは一周する間に必ずすべての if を評価する。
* 下のループは if の条件が真になったら、以下の if は評価されない。


## is_left_black() はそれでいいか？

実は、これまでのプログラムには微妙な間違いがあります。
気がついた人はいたか？
コンピュータの処理速度のためにその間違いに気がつかなかった。

[別ページ](led.html)で説明します。


----
written by hkimura.




