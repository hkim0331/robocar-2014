/*
 ============================================================================
 Name        : io.c
 Author      : Daisuke Arikawa
 Version     : 1.0
 Copyright   : All Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void ex1(void) {
	printf("11/22\nSat.\n12:00\nwith love.\n");
	printf("jun\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t7890\n");
}

void ex2(void) {
	int x=20;
	int y=2;
	printf("I am %d years old, have %d kids.\n",x,y);
}

void ex3(void) {
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(void) {
	char *name="Daisuke Arikawa";
	printf("My name is %s.\n",name);
}

void ex5(void) {
	int x;
	int name[256];

	printf("整数を入力してね:");
	scanf("%d",&x);
	printf("名前はなに？");
	scanf("%s",&name);
	printf("%sさんの入力は%d\n",name,x);
}


int main(void) {
	ex5();
	return 0;







	return EXIT_SUCCESS;
}
