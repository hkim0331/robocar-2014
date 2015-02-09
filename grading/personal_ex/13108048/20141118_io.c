/*
 ============================================================================
 Name        : io.c
 Author      : Toru Kuwatani
 Version     : 1.0
 Copyright   : All Right Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nsat.\n12:00\nwith love.\n");
	printf("jan\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t7890\n");
}

void ex2(void){
	int x=19;
	int y=0;
	printf("I am %d years old, have %d kids.\n",x,y);
}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z=%d,%u,%o,%x\n",z,z+1,z,z);//d=デシマル,u=unsigned,o=8進数,x=16進数
	printf("y=%d,%u,%o,%x\n",y,y,y,y);
}

void ex4(void){
	char *name="toru kuwatani";
	printf("My name is %s.\n",name);//s=文字列
}

void ex5(void){
	int x;
	char name[256];

	printf("整数を入力してね:");
	scanf("%d",&x);
	printf("名前は？？");
	scanf("%s",name);
	printf("%sさん、%d番ね♂\n",name,x);
}

void ex6(void){
	int x;
	char name[256];
	printf("お名前は？？");
	scanf("%s",name);
	printf("西暦何年生まれ？");
	scanf("%d",&x);
    printf("%sさん、%d")；
}

int main(void) {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	ex5();
	return 0;
}
