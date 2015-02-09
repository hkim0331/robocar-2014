/*
 ============================================================================
 Name        : io.c
 Author      : Karen Shibasaki
 Version     : 1.0
 Copyright   : All Right
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love.\n");
	printf("jun\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t7890\n");
}

void ex2(void){
	int x=20;
	int y=3;
	printf("I am %d years old, have %d kids.\n",x,y);
}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n",z,z+1,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(void){
	char *name="Karen Shibasaki";
	printf("My name is %s.\n",name);
}

void ex5(void){
	int x;
	char name[256];

	printf("整数を入力して下さい:");
	scanf("%d",&x);
	printf("名前は何ですか？");
	scanf("%s",name);
	printf("%sさんの入力は %d です。\n",name,x);
}

void ex6(void){
	int x;
	char name[256];

	printf("あなたは西暦何年生まれですか？");
	scanf("%d",&x);
	printf("");
	scanf("%s",name);
	printf("\n"name,x);
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
