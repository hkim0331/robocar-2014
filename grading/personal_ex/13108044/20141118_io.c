/*
 ============================================================================
 Name        : io.c
 Author      : Tomohiro Kubo
 Version     :
 Copyright   : All Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love.\n");
    printf("Jat\tfeb\tmar\tapr\tmay\n");
    printf("1\t23\t456\t7890\n");
}

void ex2(void){
	int x = 20;
	int y = 0;
	printf("I am %dyears oid,have %d kids.\n",x,y);
}

void ex3(void){
int z=-1;
int y=15;
printf("z = %d,%u,%o,%x\n",z,z+1,z,z);
printf("y = %d,%u,%o,%x\n",y,y,y,y);
}

void ex4(void){
	char *name= "Tomohiro Kubo";
	printf("my name is %s\n",name);
}

void ex5(void){
	int x;
	char name ;

	printf("please input integer :");
	scanf("%d",&x);
	printf("What is your name?");
	scanf("%s",name);
    printf(" Your name is %s, and %d .\n",name,x);
}

void ex6(void){
	int x,y;
	char name;
	printf("What is your name?");
	scanf("%s",name);
	printf("西暦何年生まれですか")；
	scanf("%d",&x);
	y

}

int main(void) {
ex5();
return 0;

	return EXIT_SUCCESS;
}
