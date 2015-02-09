/*
 ============================================================================
 Name        : io.c
 Author      : Ryota Honda
 Version     :1.0
 Copyright   : All Right  Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	int age = 20;
	int GF = 20;
	printf("I am %d years old.\n I have %d kids.\n",age,GF);
}
void ex2(void)//\tの練習
{
	printf("123\t 3456\t apple\t 1\t 2\n");
	printf("a\t b\t c\t d\t e\t\n");
	printf("spring\tsummer\tautum\twinter\n");
}
void ex3(void)
{
	int z = -1;
	printf("z=%d,%u,%o,%x\n",z,z,z,z);
}
void ex4(void)
{
	char *name="Ryota Honda";
	printf("My name is %s.\n",name);
}
void ex5(void)
{
	int x;

	printf("整数を入力してね");
	scanf("%d",&x);
	printf("x=%d\n",x);
}
void ex6(void)
{
	char name[255];

	printf("あなたの名前は何ですか？==>");
	scanf("%s",name);
	printf("%sさん、さようなら\n",name);
}
int main(void) {

	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	ex6();
	return 0;
}
