/*
 ============================================================================
 Name        : io.c
 Author      : Shohei Kuwata
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void) {
	int age=52;
	int gf=3;
	printf("I am %d years old.\nI have %d girl friends.\n", age, gf);

	return 0;
}

void ex2(void){
	printf("123\t3456\tapple\t1\2\n");
	printf("a\tb\tc\td\te\t\n");
	printf("spring\tsummer\tautum\twinter\n");
}

void ex3(void){
	int z=20;
	printf("z= %d, %u, %o, %x,\n",z,z,z,z);

int main(void){
	ex3();
	return 0;
}
}

