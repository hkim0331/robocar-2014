/*
 ============================================================================
 Name        : io.c
 Author      : Syuya Tanaka
 Version     : 1.0
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){

	int age=52;
	int gf=3;

	printf("I am %d years old\nI have %d kids.\n", age, gf);
}

void ex2(void)
{
	printf("123\t3456\tapple\t1\t2\n");
	printf("a\tb\tc\td\te\t\n");
	printf("spring\tsummer\tautum\twinter\n");
}

void ex3(void)
{
	int z=-1;
	printf("z= %d, %u ,%o, %x\n",z,z,z,z);
}

void ex4(void)
{
	char *name="syuya tanaka";
	printf("my name is %s\n",name);
}

void ex5(void)
{
	int x;

	printf("整数を入力してください:");
	scanf("%d",&x);
	printf("your input is %d.\n", x);

}

void ex6(void)
{
	char name[255];

	printf("あなたの名前は何ですか==>");
	scanf("%s" , name);
	printf("%sさん、おはようございます。\n");

}
int main(void){

    ex6();

	return 0;
}
