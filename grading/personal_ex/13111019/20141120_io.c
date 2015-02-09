/*
 ============================================================================
 Name        : io.c
 Author      : Kazufumi Sakaguchi
 Version     :1.0
 Copyright   : All Rights Reserves
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void ex1(void){
	int age=20;
	int gf=0;
	printf("I am %d years old.\nI have %d girl friends.",age,gf);
}
void ex2(void){
	printf("123\t3456\tapple\t\n");
}
void ex3(void){
	int z=20;
	printf("z=\t%d, \t%u, \t%o, \t%x\n",z,z,z,z);
}
void ex4(void){
	char *name="Kazufumi Sakaguchi";
	printf("My name is %s.\n",name);
}
void ex5(void){
	int x;
	printf("整数を入力してね\n");
	scanf("%d",&x);
	printf("Your imput is=%d\n",x);
}
void ex6(void){
	char name[255];
	printf("あなたの名前はなんですか？");
	scanf("%s",name);
	printf("%sさん、おはようございます。\n",name);
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	ex6();
	return 0;
}
