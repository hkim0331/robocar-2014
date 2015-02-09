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
	printf("学園祭いつ？\n");
	printf("11/22\nSat.\n12:00\nwith love.\n");
	printf("Jan\tFeb\tMar\n");
	printf("1\t2\t3\n");
}

void ex2(void) {
	int x=20;
	int y=3;
	printf("I am %d years old, have %d kids\n",x,y);
}

void ex3(void) {
	int z=-1;
	int t=10;
	printf("z=%d, %u, %o, %x\n",z,z+1,z,z); /*d:10進数,u:unsigned,o:8進数,x:16進数*/
	printf("z=%d, %u, %o, %x\n",t,t,t,t);
}

void ex4(void) {
	char *name="ryo kamikogawa";
	printf("my name is %s.\n",name); //%s:文字列
}

void ex5(void) {
	int x;
	char name[256];

	printf("整数を入力して:");
	scanf("%d",&x);
	printf("input is %d\n",x);

	printf("名前は？\n");
	scanf("%s",name);
	printf("%sさん、%d番ですので。\n",name,x);
}

void ex6(void) {
	int i, j;
	printf("あなたは何歳ですか？");
	scanf("%d",&i);
	j=2014-i;
	printf("あなたは%d年生まれですね",j);
}

int main(void) {

	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();

	return 0;
}
