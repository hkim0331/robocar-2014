/*
 ============================================================================
 Name        : io.c
 Author      : Kajiwara Atsushi
 Version     :1.0
 Copyright   : All Right
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void)
{
	int age=21;
	int kids=3;

	printf("I am%dyears old\nI have%dkids.\n", age, kids);
}

void ex2(void)// \t の練習
{
	printf("123\t3456\tapple\t1\t2\n");
	printf("a\tb\tc\td\te\t\n");
	printf("spring\tsummer\tautum\twinter\n");

}

void ex3(void)
{
	int z=-1;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
}

void ex4(void)
{
	char *name="atsushi kajiwara";
	printf("my name is %s \n",name);
}

void ex5(void)
{
	int x;

	printf("整数を入力してね:")
	scanf("%d",&x);
	printf("your input is%d.\n",x);
}

void ex6(void)
{
	char name [225];

	printf(" あなたの名前は==>");
	scanf("%s",name);
	printf("%sさん、おはようございます。\n");
}

int main(void){

	ex3();
	return 0;
}
