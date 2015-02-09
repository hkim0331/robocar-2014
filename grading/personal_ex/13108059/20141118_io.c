/*
 ============================================================================
 Name        : io.c
 Author      : Naoya Shinozaki
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love.\n");
	printf("jun\nfeb\ntmar\ntapr\nmay\n");
	printf("1\n23\n456\n7890\n");
}

void ex2(void){
	int x=20;
	int y=3;
	printf("I am %d years old,having %d kids.\n",x,y);
}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(void){
	char *name="naoya shinozaki";
	printf("my name is %s.\n",name);
}

void ex5(void){
	int x;
char name[256];
	printf("整数を入力してね:");
	scanf("%d",&x);
	printf("名前はなーに？");
	scanf("%s",name);
	printf("%sさん、%dね\n",name,x);
}

void ex6(void){
	int x;
	char name[256];
	printf("西暦":);
	scanf("":);

}
int main(void) {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	ex5();
	return 0;
}
