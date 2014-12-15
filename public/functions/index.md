## 関数

関数が使えないうちはプログラミングはまったく楽しくない。

関数が使えるようになるとプログラムは分かりやすく、作りやすく、改良しやすくなる。

関数を理解するために理解すべきこと

* 関数の名前 --- どんな名前でその関数は呼び出されるか
* 引数 --- どんな種類の引数をいくつ受け取るか
* 戻り値 ---　関数を実行した結果、どんな種類の情報がえられるか
* 関数を定義するとはどういうことか、どんなふうに定義するか
* 関数を呼び出すとはどういうことか、どんなふうに呼び出せるのか

### 整数二つのうち、「小さい方はこれ」っていうプログラム（関数）を作りたい。

Cプログラマは以下の三つを考える。

* その関数には smaller という名前をつけよう。
* 「整数二つを受け取る」んだから、関数 smaller の引数はふたつ、ともに int だ。それらを区別するためにそれぞれ違った名前 x, y で呼ぼう。
* 「小さい方」は整数だ。だから関数 smaller の戻り値は整数だ。

ということで次をプログラムする。

````c
int smaller(int x, int y)
{
	if (x < y) {
		return x;
	} else {
		return y;
	}
}

````

プログラムの仕方はただ一通りではなく、次のような定義の仕方をしてもよい。

````c
int smaller(int x, int y)
{
	int z;

	if (x < y) {
		z = x;
	} else {
		z = y;
	}
	return z;
}

````

こんな書き方もあるが、覚えんでもよい。
````c
int smaller(int x, int y)
{
	return (x<y) ? x : y;
}
````

関数は return 文に出会うか、関数定義の末尾に到着すると終了する。
ほとんどの関数は、
後ろの方で述べる戻り値 void の関数をのぞき、
関数定義の末尾に到着することはない。

### 関数 small を呼び出す

関数 smaller を定義したら、それを呼び出すにはその名前 smaller の後ろ、
()の中にsmallerが必要とするデータ（引数）を入れる。

呼び出しがすんだら関数 smaller は渡した引数の小さい方の整数を返してくる。
戻り値を煮るなり焼くなりするのは関数 smaller を呼び出したプログラム（関数）の責任。

````c
int main(void)
{
	int a=3;
	int b=4;
	int c;

	c = smaller(a,b); // smaller(a,b)の戻り値がcに代入される
	printf("c=%d\n",c);
	return 0;
}

````


### c = smaller(a,b)って？

c = 4 を「c に 4 を代入する」と読まずに、こう読んだらどうか、「c に 4 を計算した結果を代入する」。
4 を計算した結果は 4 だ。計算して値を求めることを「評価する」というと頭良く聞こえる。

c = smaller(a,b) は 「c に smaller(a,b) を計算した結果を代入する」。
smaller(a,b) の計算結果とはsmaller(a,b)が return で返してくる値のことで、
この場合、aとbの小さい方の整数。

### なんで関数を定義するか？

便利なことがあるから。

3つの整数の最小値をプリントする関数を、

* 関数 smaller を利用しないで、
* 関数 smaller を利用して、

書いてみる。整数 a,b,c は scanf で読ませてもいいが、関数の働きに注意を向けるため、省略。

````c
#include <stdio.h>
int main(void)
{
	int a=10;
	int b=20;
	int c=30;

	if (a<b) {
		if (b<c) {
			printf("%d\n",a);
		} else {
			if (a<c) {
				printf("%d\n",a);
			} else {
				printf("%d\n",c);
			}
		}
	} else {
		if (a<c) {
			printf("%d\n",b);
		} else {
			if (c<b) {
				printf("%d\n",c);
			} else {
				printf("%d\n",b);
			}
		}
	}
}
````

きっとどっかで間違っている。自信なし。

smaller を利用してみる。main の上、#include の下に smaller が定義されていると仮定。

````c
#include <stdio.h>
...
int main(void)
{
	int a=10;
	int b=20;
	int c=30;

	printf("%d\n",smaller(a,smaller(b,c)));
	return 0;
}
````

すっきり！

4つの整数の最小値を求めることが必要になっても、
smaller(smaller(a,b),smaller(c,d))
などと応用が利く。

以下、main にベタ書きせず、できるだけ関数で書いてみよ。

### 直角三角形？

a,b,cを直角三角形の３辺の長さとする。その３角形は直角三角形かどうかを判定する。

````c
#include <stdio.h>
int larger(int a, int b)
{
	if (a<b) {
		return b;
	} else {
		return a;
	}
}

int max(int a, int b, int c)
{
	return larger(a, larger(b,c)));
}

int main(void)
{
	int a=10
	int b=20;
	int c=30;

	if (a==max(a,b,c)) {
		x = b;
		y = c;
		z = a;
	} else if (b==max(a,b,c)) {
		x = a;
		y = c;
		z = b;
	} else {
		x = a;
		y = b;
		z = c;
	}

	if (x*x+y*y == z*z) {
		printf("直角三角形\n");
	} else {
		printf("直角三角形ではない\n");
	}
	return 0;
}
````

larger 定義して、それを利用して max を定義するとこは学習できた。
別のアプローチでプログラムしてみる。
a,b,cを大きさの順に並べ替えなくても比較を３回すればいいだろう。

````c
//改良、sub() はやりすぎか？
#include <stdio.h>
int sub(int a, int b, int c)
{
	return a*a + b*b == c*c;
}

int is_normal(int a, int b, int c)
{
	return sub(a,b,c) || sub(b,c,a) || sub(c,b,a);
}

int main(void)
{
	int a;
	int b;
	int c;

	//a,b,c には整数を読み込むこと。
	if (is_normal(a,b,c)) {
		printf("直角三角形\n");
	} else {
		printf("直角三角形にならない\n");
	}
	return 0;
}
````

同じ内容なら、プログラムが短い方が読みやすい。タイプの量も少なくて済む。バグも入りにくくなる。

### 素数

unsigned int の範囲でできるだけ大きな素数を探し当てよう。
素数は 1 と自分以外、自分を割り切る整数がない数。

* その関数の名前として何がふさわしいだろう？　--- is_prime でどうだ？
* その関数は何を引数にとるべきか？ --- 判定すべき整数 n。問題文に unsigned int の範囲とあるから...
* その関数の戻り値はどんな値とすべきか？ --- C では真はなんだった？偽はなんだった？

ということで、整数nが素数かどうかを判定する関数の書き出しはこんな感じ、

````c
int is_prime(unsigned int n)
````

中身はどうなる？下を見ずに、まず、自分で書いてみれ。

````c
int is_prime(unsigned int n)
{
	int i;
	for(i=2; i<n; i++) {
		if (n%i==0) {
			return 0; // 素数じゃない。
		} else {
			;
		}
	}
	return 1;//素数だ。
}
````

この関数 is_prime()には小さなバグがある。それはなんでしょう？どう変更すればいい？
考えてみること。君らは考えようとしないのがダメと思う。

is_prime()を呼び出すプログラム、

````c
int main(void)
{
	unsigned int i= 1;

	while (1) {
		if (is_prime(i)) {
			printf("%u is prime\n",i);
		} else {
			i++;
		}
	}
	return 0;
}
````

素直なプログラムだが、こりゃー大変だ。一番大きな素数が求まるまでに何時間かかるか？
(答え、無限ループのバグがあり、止まらない)

ズルというか、アイデアを絞る。一番大きい数から調べて、最初に見つかった数が答えだ。
また、signed int で -1 となるビットパターンが unsigned int の最大値だったことを上手に使う。

````c
int main(void)
{
	unsigned int i= -1;

	while (1) {
		if (is_prime(i)) {
			printf("%u is prime\n",i);
			return 0;
		} else {
			i--;
		}
	}
	return 0;
}
````

このプログラムはまだ甘ちゃんです。もう少し勉強すれば数100倍速いプログラムにできます。

````
$ time ./prime
4294967295 is not prime
4294967294 is not prime
4294967293 is not prime
4294967292 is not prime
4294967291 is prime

real	0m18.240s
user	0m18.212s
sys	0m0.010s
````

答え　4294967291　を見つけるのに 18 秒かかっています。改良プログラム prime2での実行。

````
$ time ./prime
4294967295 is not prime
4294967294 is not prime
4294967293 is not prime
4294967292 is not prime
4294967291 is prime

real	0m0.011s
user	0m0.001s
sys	0m0.001s
````

1,600倍の高速化に成功！どんな工夫だったでしょう？

### 完全数

完全数とは自分を除く約数の和が自分と等しくなる整数のこと。映画「博士が愛した数式」に出てくる。
たとえば 6 の約数は 1,2,3。 足すと6になるので6は完全数。
そのほか28も完全数。次の完全数はいくつでしょう？できるだけ大きな完全数を見つけなさい。

* 関数の名前は　is_perfect、引数は判定すべき整数 n 、戻り値は0/1で真/偽とする。

````c
int is_perfect(int n)
{
	int sum=0;
	int i;

	for (i=1; i<n; i++) {
		if (n%i == 0) {
			sum += i;
		} else {
			;
		}
	}
	return sum == n;
}
````

sum は定義時にすぐ0に初期化するのにiは	初期化しない理由はすぐ下で1に初期化するからです。
return sum == n; の意味、わかりますか？

is_perfect()を速くできるかな？

### FizzBuzz

### guess me!

### 100言ったら負けゲーム



## 戻り値や引数が void とは？

void は ''I have nothing to do.'' の nothing と同じ意味。

戻り値がない関数は本来行儀が悪すぎ。


