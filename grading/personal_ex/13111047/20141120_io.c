/*
 ============================================================================
 Name        : io.c
 Author      : Toshiki Matsui
 Version     : 1.0
 Copyright   : All Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void)
{
	int age=19;
	int gf=0;
	printf(	"I am %d years old.\nIhave %d kids.\n", age ,gf);

}

void ex2(void)// \tの練習
{
	printf("123\t3456\tapple\t1\t2\n");
	printf("a\tb\tc\td\t\n");
	printf("spring\tsummer\tautum\twinter\n");
	}

void ex3(void)
{
	int z=-1;
	printf("z= %d, %u, %o, %x\n" ,z,z,z,z);
	}

void ex4(void)
{
 char *name="Toshiki Matsui";
 printf("my name is %s.\n",name);
//%sは文字列
}

void ex5(void){
	int x;

	printf("整数を入力してください");
	scanf("%d",&x);
	printf("your input is %d\n",x);
}

void ex6(void){
	char name[255];

	printf("あなたの名前は何==>");
	scanf("%s",name);
	printf("%sさん、おはようございます\n");
}

int main(void) {

    ex6();
	return 0;
}
