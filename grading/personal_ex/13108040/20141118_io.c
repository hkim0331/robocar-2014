/*
 ============================================================================
 Name        : io.c
 Author      : Kazuya Kishi
 Version     :1.0
 Copyright   : All Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
}
void ex2(void){
	int x=52 ;
	int y=3 ;
	printf("I am %d years old, have %d kids.\n",x,y);
}
void ex3(void){
	int z=-1;
	int y=15;

	printf("z= %d, %u, %o, %x\n",z,z,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}
void ex4(void){
	char *name="kazuya kishi";
	printf("my name is %s\n",name);
}
void ex5(void){
	int x;
	char name[256];

	printf("整数を入力してください。");
	scanf("%d",&x);
	printf("名前を入力してください。");
	scanf("%s",name);
	printf("%sの入力は%dです。\n",name,x);
}
void ex6(void){
	int x;
	char name[256];

	printf("名前を入力してください。");
	scanf(%s,name);
	printf("年齢を入力してください。");
	scanf(%d,&x);


}
int main(void) {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	ex5();
	return 0;
}
