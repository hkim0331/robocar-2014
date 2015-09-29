## 色を測る

<div>
  <img src="images/colors.png" style="width:60%;">
</div>

今週の課題は「色を測る」。とは言うものの、ロボカーはグレースケール値でしか、色を認識できない。明るさを測定できるだけだ。

黒、白、灰色、赤、青、緑、黄色をロボカーは整数幾つと認識するか。それらの色を明るさ順に並べよ。

### step は応用できるか

方向違い。使うとしたら測定後の場所移動だな。

各色のテープの上にロボカーのセンサを乗せ、一定時間(n回)明るさを測定し、その平均値を　printf() できないから、音で鳴らそう。

### 配列を使えないグループ

配列使わずできても C または D　コース。配列使えるようになろう。

配列使えるチームもひとまず以下のコードを読む。特に関数 average() のあたり。

関数はなにを引数にして何を返すか、
プログラムはどんな動作をするか、分からん受講生は危険。D コース。
早めに必死に復習してこい。

````c
void beep(void) {
  BuzzerSet(100,100);
  BuzzerStart();
  Wait(100);
  BuzzerStop();
  Wait(100);
}

int average(void) {
  int x0, x1, x2, x3, x4;

  x0 = ADRead(0);
  Wait(100);
  x1 = ADRead(0);
  Wait(100);
  x2 = ADRead(0);
  Wait(100);
  x3 = ADRead(0);
  Wait(100);
  x4 = ADRead(0);

  return (x0 + x1 + x2 + x3 + x4)/5;
}

void color(void) {
  int i;
  int n=average();

  for (i=0; i<n; i++) {
    beep();
  }
}
````

* 関数 average() は 100msec ごとに ADRead(0) し、5回の平均を戻り値とする。
  本来平均は小数点付きの数（C言語の世界では *実数* と呼ぶ）になるが、
  手抜きして整数商にしている。
* もどってきた回数分、ブザーを鳴らす。これは大変。黒だったら 1000 回近くなる。

また、5回の測定値の平均でなく、100回の平均をとりたくなったらどうする？
配列使えないとひじょうにつらくなる。

### average() 修正

x0,x1,x2,x3,x4 を配列で書き直す。

x0 の代わりに x[0], ..., x4 の代わりに x[4]になる。ただし、配列は使う前に宣言しないといけない。

````c
//あまり改良になってないaverage()
int average(void) {
  int x[5]; //x[0] から始まる５個。配列の最後はx[4]。

  x[0] = ADRead(0);
  Wait(100);
  x[1] = ADRead(0);
  Wait(100);
  x[2] = ADRead(0);
  Wait(100);
  x[3] = ADRead(0);
  Wait(100);
  x[4] = ADRead(0);

  return (x[0]+x[1]+x[2]+x[3]+x[4])/5;
}
````

これだとタイピング疲れるだけ。ループで書き直し。

````c
int sum(int a[], int from, int to) {
  int ret=0;
  int i;

  for (i=from; i<to; i++) {
    ret += a[i];
  }
  return ret;
}

int average(void) {
  int x[5]; //x[0] から始まる５個。配列の最後はx[4]。
  int i;

  for (i=0;i<5;i++) {}
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,5)/5;
}
````

配列を引数にするやり方を覚えること。

最近の C 言語は配列の大きさを実行時に決めることができる（わしが学生の頃はコンパイル時に決まってないとエラー。時代は進んだ）ので、以下でもよい。関数 sum は上のままなので省略。

````c
int average(int n) {
  int x[n];
  int i;

  for (i=0;i<n;i++) {}
    x[i] = ADRead(0);
    Wait(100);
  }
  return sum(x,0,n)/n;
}
````

### ブザーを1000回も聞きたくねーぞ

当たり前です。beep()の呼び出しを変えます。

````c
  for (i=0; i<n; i+=100) {
    beep();
  }
````

これにて　i　は100ずつ増える。nが1000ならブザーは1000/100の10回鳴ります。

### 問題: 黒、白、グレー、赤、黄色、緑、青を明るさの順にならべよ。

答えを書いたようなもんです。簡単。

今日の課題は違います。

## 今日の課題

1. 同じ長さの配列を二つ用意しなさい。
1. 片方の配列には進むべき方向（前、前、左、右、後ろ、前を表す符号）を入れる。
1. もう一方の配列には進むべき時間（100,100,50,50,200,100みたいに）を入れる。
1. ロボカーをこの配列に入った命令にしたがって動作するように（前100、前100、左50、右50、前200、後ろ100、END）しこめ。
1. さらに音を出す、LEDを光らすような命令を配列に入れよう。

----
written by hkimura.

