/*
 ============================================================================
 Name        : io.c
 Author      : 
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int ex1(void)
{
	int age=20;
	int gf=3;

	printf("I am %d years old.\nI have %d kids.\n",age,gf);
}

void ex2(void)// \t の練習
{
	printf("123\t3456\tapple\t1\t2\t\n");
	printf("a\tb\tc\td\te\t\n");

}

void ex3(void)
{
	int z=20;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
}

void ex4(void)
{
	char *name="takahiro hashimoto";
	printf("my name is %s.\n",name);
}

void ex5(void){
	int x;

	printf("整数を入力してね");
	scanf("%d",&x);
	printf("your input is %d\n",x);
}

void ex6(void){
	char name[255];

	printf("あなたの名前は何ですか==>");
	scanf("%s", name);
	printf("%sさん、おはようございます。\n");
}

void kadai(void){

}

int main(void) {

	ex6();
	return 0;

}
