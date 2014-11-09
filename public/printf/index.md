## printf()/scanf()

関数 printf()とscanf()はC言語のもっともヘンテコな部分。わかりずらくて当たり前。
それでも大学生なら理解できないと落第だ。

<div align='center'>
  <img src="images/printf_scanf.png" width="70%">
</div>

* printf()はキーボードから入力されたデータをCプログラムに取り込む（出力）。
* scanf()はプログラム中の変数の値をディスプレイに表示する（入力）。

ロボカーにはモーターやフォトセンサがあってもディスプレイやキーボードはないので、printf/scanf を使う場所はない。

しかし、一般に、コンピュータはなにかしらデータをコンピュータ外部から入力し、その計算結果をなんとかして外部に出力できないとコンピュータとしての意味がない。
ヘンテコでも身につけねば。

コンピュータへの入力(Input)、コンピュータからの出力(Output)のことを短く I/O と言ったりする。

### printf("フォーマット", 変数, 変数, 変数, ...);

関数 printf() をプログラム中で利用するには、プログラムの先頭付近に、

````c
#include <stdio.h>
````

が必要。`#include` と `<stdio.h>`の間にはスペース文字を入れよう。#include と関数とを区別できない教員はそのことを知らない。
同じく、if と関数の違いを理解できない教員は if と () の間のスペースをタイプしない。
ま、スペースなくてもコンパイルエラーにならず動作も変わらないんだけど、
「自分はマクロと関数、トークンの区切りを理解してプログラムを書いている」と胸を張るにはあるべきところにスペースあったほうがいいですな。

次の例をきちんと理解できれば合格。

````c
#include <stdio.h>

void ex1(void)
{
  int hkimura = 52;
  int kids = 3;

  printf("I am %d yeas old, have %d kids\n", hkimura, kids);
}

int main(void)
{
  ex1();
  return 0;
}
````

* "I am %d yeas old, have %d kids\n" の部分がディスプレイに表示される。

* %d は文字列中の穴<br>
この穴は対応する変数（定数の場合もある）を decimal、つまり十進の整数として表示せよの意味になる。
対応する変数（定数）はフォオーマットの後ろ、コンマで区切って指定する。%dのほか、
    * %o 八進整数
    * %x 16進整数
    * %u 符号なし整数（１０進）
    * %f 小数点付き
    * %s 文字列

など。

* \n は特別な意味を持つ<br>
\ と n の２文字で「改行」の意味になる。\n のほか、使うのは \t で「タブ」くらいか。

#### 演習2
次の関数 ex2()を上のプログラムの適切な場所に定義し、関数 main() から呼び出した時、
ディスプレイに何と表示されるか？

````c
void ex2(void)
{
  int x = 100;
  printf("x = %d, %o, %x\n", x, x, x);
}
````

#### 演習3
次の関数 ex3()を上のプログラムの適切な場所に定義し、関数 main() から呼び出した時、
ディスプレイに何と表示されるか？

````c
void ex3(void)
{
  int x = -1;
  printf("x = %d, %x, %u\n", x, x, x);
}
````

#### 演習4
次の関数 ex4()を上のプログラムの適切な場所に定義し、関数 main() から呼び出した時、
ディスプレイにどんなふうに表示されるか？

````c
void ex4(void)
{
  printf("0\t123\t45\t6\t789\n");
  printf("abcd\tef\tg\thij\tklmop\n");
  printf("\t|\t|\t|\t|\n");
  printf("hello\n\n\nworld\n\n\n!!!");
  return 0;
}
````

### scanf("書式", 変数のアドレス, 変数のアドレス, ...);

printf()よりもさらにややこしいのが scanf()だ。

* 変数がスカラー型のとき（int, short, double など）のとき、変数のアドレスは `&変数` となる。
* 変数が配列のとき、変数のアドレスは ｀変数`。
* C では文字列を char の配列として表現することを覚えておこう。

````c
#include <stdio.h>

void ex5(void)
{
  int x;

  scanf("%d",&x);
  printf("%d が入力されました\n", x);
}

int main(void)
{
  ex5();
  return 0;
}
````

````c
#include <stdio.h>

void ex6(void)
{
  char name[10];

  printf("名前を教えてください=> ");
  scanf("%s", name);
  printf("%s さんですね。\n", name);
}

int main(void)
{
  ex6();
  return 0;
}
````

#### 演習6
上の ex6 はウィルス作者がターゲットとするプログラムの第1番になる。理由を推測しなさい。
どんな入力をするとプログラムが腹を下すか（エラーになるか）考えてみよ。


#### 演習7

````c
void ex7(void)
{
  char family[10];
  char given[10];

  printf("苗字と名前を教えてください=>");
  scanf("%s %s", family, given);
  printf("%s %s さんですね。\n", family, given);
}
````

### scanf() の戻り値

----
written by hkimura.
