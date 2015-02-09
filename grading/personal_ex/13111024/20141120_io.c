/*
 ============================================================================
 Name        : io.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void)//\tの練習
{
	printf("I am 20 years old.\n I have had 6 girl friend.\n");
}

void ex2(void)
{
	int age=20;
	int gf=6;
	printf("I am %d years old.\n I have had %d girl friend.\n",age,gf);
}

void ex3(void)//%d 整数,%u 10進数,%o 8進数,%x ？
{
	int z=-1;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
}

void ex4(void)
{
	char *name"Shiraboshi"
	printf("my name is %s,\n",name)
}

void ex5(void)
{
	int x;
	printf("整数を入力してね")
	scanf("%d",&x);
	printf("your input is %d,\n",x);
}

void ex6(void)
{
	char name[255];

	printf("あなたの名前は何ですか==>");
	scanf("%s",name);
	printf("%sさん、おはようございます,\n");
}

int main(void)
{
	ex6();
	return 0;
}
