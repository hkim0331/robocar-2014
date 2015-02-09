/*
 ============================================================================
 Name        : io.c
 Author      : Inoue Shinsuke
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void) {
	printf("11/22\nSat.\n12:00\n");
	printf("jan\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456");
}

void ex2(void) {
	int x=22;
	int y=0;
	printf("I am %d years old, have %d kids.\n",x,y);
}

void ex3(void) {
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(void) {
	char *name="Inoue Shinsuke";
	printf("My name is %s.\n",name);
}

void ex5(void) {
	int x;
	char name[256];


	printf("整数を入力して:");
	scanf("%d", &x);
	printf("名前はなに？");
	scanf("%s",name);
	printf("%sさんは%dって入力したね\n",name,x);
}

void ex6(void) {
	int x;
	char name[256];

	printf("名前はなに？");
	scanf("%d",x);
	printf("西暦何年生まれ？");
}
int main(void) {
	ex5();
	return 0;
}
