## ファイル

ハードディスク等に記録されたデータ。

* C 言語以外のツールでファイルを扱う。
* C 言語の枠内（ライブラリ）でファイルを扱う。


## LPCXpresso 使わずに

LPCXpresso 使っても当然できるが、以下をエディタで作って、ファイル　watch.c にセーブ。

````c
// watch.c
#include <stdio.h>

int main(void) 
{
	int c;

	while (1) {
		c=fgetc(stdin);//stdinは「キーボードから」の意味と思ってよし
		if (c==(-1)) {
			break;
		} else {
			fputc(c, stdout);//stdoutは「ディスプレイへ」の意味と思ってよし
		}
	}
	return 0;
}
````

コンパイル。

````
$ cc watch.c
````

a.out 以外の名前にコンパイルするときは、

````
$ cc -o watch watch.c
````

実行する。

````
$ ./watch
$ ./watch < watch.c
$ ./watch < /home/t/hkim/hello.txt
````

以上、'<' を利用してファイルを読む、でした。

## fopen()を利用する
（未完)

````c
// watch.c
#include <stdio.h>

int main(void) 
{
	int c;
	char fname[100];
	FILE *inf;

	// 以下の2行はファイル名をキーボードから読む。
	printf("file name? ");
	scanf("%s",fname);

	// ファイル名で表されるファイルを開く。
	inf = fopen(fname,"r");

	while (1) {
		c=fgetc(inf); // inf は fopen()で開いたファイル。
		if (c==(-1)) {
			break;
		} else {
			fputc(c,stdout);
		}
	}
	fclose(inf); // ファイルを読み終えたら忘れずにクローズ。
	return 0;
}
````

* fclose()を忘れ、大量に watch するとコンピュータがメモリ不足を起こし、死にます。

