/*
 ============================================================================
 Name        : io.c
 Author      : Uchimura Hitomi
 Version     : 1.0
 Copyright   : All Right Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love\n");
	printf("kyou\tkana\n");
    printf("1\t23\t456\t7890\n");
}

void ex2(void){
	int x=20;
	int y=0;
	printf("I am %d years old and have %d kids.\n",x,y);
}

void ex3(void){
	int x=-1;
	int y=15;
	printf("x=%d,%u,%o,%x\n",x,x,x,x);
	printf("y=%d,%u,%o,%x\n",y,y,y,y);
}

void ex4(void){
	char *name="uchimura hitomi";
	printf("My name is %s.\n",name);
}

void ex5(void){
	int x;
	printf("please input integer ");
	scanf("%d",&x);
	printf("input is %d\n",x);
}

void ex6(void){
	int x,c;
	char name[256];
	x=0;
	c=2014-x;

	printf("年は？");
	scanf("%d",&x);
	printf("名前は？\n");
    scanf("%s",name);
    printf("%sさん%d歳、%d生まれですね\n",name,x,c);
}

int main(void) {
//ex1();
//ex2();
//ex3();
//ex4();
//ex5();
ex6();
return 0;
}
