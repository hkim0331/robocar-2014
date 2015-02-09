/*
 ============================================================================
 Name        : io.c
 Author      : yuhei hamaoka
 Version     :1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("a\nb\nc\n");
	printf("d\te\tf\n");
	printf("1\t2\t3\n");
}

void ex2(void){
     int x=21;
     int y=3;
     printf("i am %d yeares old\n,having %d kids\n",x,y);
}

void ex3(void){
	int z=-1;
	int y=15;

	printf("z= %d, %u, %o, %x\n",z,z,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}

void ex4(void){
	char *name="yuhe hamaoka";
	printf("my name is %s.\n",name);
}

void ex5(void){
	int x;
	char name[256];

	printf("plese input integer:");
	scanf("%d" , &x);
	printf("namae is");
	scanf("%s",name);
	printf("%sさん、 is %d\n",name,x);
}

void ex6(void){

}

int main(void) {
	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	return 0;

}
