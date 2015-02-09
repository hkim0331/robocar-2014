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

void ex1(void){

	int age=52;
	int gf=3;

	printf("I am %d years old.\nI have %d kids friends.\n",age,gf);//\n 改行
}

void ex2(void){
	printf("123\t3456\tapp\t2\n");
	printf("a\tb\t");
	printf("spring\tfall\t");
}

void ex3(void){
	int z=-1;
	printf("z=%d,%u,%o,%x\n",z,z,z,z);//%d 整数

}

void ex4(void){
	char *name="daishaku ayano";
	printf("My name is %s.\n",name);//%s文字列

}

void ex5(void){
	int x;
	printf("整数を入力してね ");
	scanf("%d",&x);
	printf("your input is %d\n",x);
}

void ex6(void){
	char *name[255];
	printf("あなたの名前は何ですか？ ");
	scanf("%s",name);
	printf("%sさんおはようございます｡\n");
}

int main(void) {



	ex6();

	return 0;
}
