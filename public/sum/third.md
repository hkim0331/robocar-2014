## ループ

いろいろ種類あっても一つ知っていればいい。わかりやすいのは while。
初期化や脱出条件、再設定が一箇所にあり、覚えてしまえば便利なのは for だろう。

### while

syntax:
````c
while (ここが真ならループを実行) {
  ....
  ....
}
````

関数 scanf() は入力がエラーになると定数 EOF を返す（EOF は stdio.h で -1 と定義されている）。
それを使って不特定多数の整数の和を求めよう。今度は負の数も足せるぞ。受講生はプログラムが読めるか？

````c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int x;
  int sum=0;

  while (scanf("%d",&x) != EOF) {
    sum += x;
  };
  printf("sum=%d\n",sum);
  return 0;
}
````

scanf("%d",&x)は正しく整数をxに読み込むと 1 を返してくる。読めなかったら EOF。

* 正しく読めたときは 1 != EOF を計算することになって答えは真。ループ続行。
* 正しく読めなかったときは EOF != EOF は成り立たず偽。ループ脱出。

いろんな書き方がある。

````c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int x;
  int sum=0;

  while (1) {
    if (scanf("%d",&x)==EOF) {
      break;
    } else {
      sum += x;
    }
  };
  printf("sum=%d\n",sum);
  return 0;
}
````

#### 問題

while を使って和を求めるもっと別の方法を考えよ。

### for

syntax:
````c
for (ループに入る前に一度だけ; ループが終わったら判断; ループが終わったら実行) {
  ....
  ....
}
````

### break, continue

* プログラムが break を実行すると、 break を含むもっとも内側のループから抜ける。
* プログラムが continue を実行すると、 continue を含むもっとも内側のループの先頭に戻る。

````c
int i;
int j;

for (i=0; i<10; i++) {
  for (j=0; j<10; j++) {
    if (i*j > 50) {
      break;
    } else {
      printf("i*j=%d\n",i*j);
    }
  }
  printf("脱出しました。i=%d, j=%d\n",i,j);
}
````

