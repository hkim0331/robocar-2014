/*
 ============================================================================
 Name        : io.c
 Author      : Hideki Ngatomo
 Version     : 1.0
 Copyright   : All rights reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void) {
	int age=20;
	int gf=0;

	printf("I am %d years old.\nI have %d girl friends.\n",age,gf);
}

void ex2(void){
	printf("123\t3456\tapple\t2\n");
	printf("a\tb\tc\td\te\t\n");
	printf("spring\tsummer\tautum\twinter\t\n");
}

void ex3(void){
	int z=-1;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
}

void ex4(void){
	char *name="nagatomo hideki";
	printf("my name is %s.\n",name);
}

void ex5(void){
	int x;

	printf("整数を入力してね:");
	scanf("%d",&x);
	printf("x=%d\n",x);
}

void ex6(void){
	char name[255];

	printf("あなたの名前は何ですか==>");
	scanf("%s",name);
	printf("%sさん、おはようございます。\n",name);
}

int main(void) {
	ex6();
	return EXIT_SUCCESS;
}
