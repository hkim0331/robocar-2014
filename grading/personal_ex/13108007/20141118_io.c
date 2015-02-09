/*
 ============================================================================
 Name        : io.c
 Author      : ando kazumi
 Version     : 1.0
 Copyright   : ALL Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love.\n");
	printf("jan\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t7890\n");
}

void ex2(void){
	int x=20;
	int y=0;
	printf("I am %d years old, have %d kids\n",x,y);
}

void ex3(void){
	int z=-1;
	int y=15;

	printf("z= %d, %u, %o, %x\n",z,z+1,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(void){
	char *name="kazumi ando";
	printf("my name is %s.\n",name);
}

void ex5(void){
	int x;
	char name[256];

	printf("please input integer:");
	scanf("%d",&x);
	printf("名前は？");
	scanf("%s",name);
	printf("input is %d\n",x);
	printf("%s\n",name);
}

void ex6(void){
	int x;
	char name[256];

	printf("名前は?\n");
	scanf("%s",name);
	printf("何年生まれ?");
	scanf("%d",&x);
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
