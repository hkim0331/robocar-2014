/*
 ============================================================================
 Name        : io.c
 Author      : kenshirou tsuge
 Version     :1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void)
{
	int age=22;
	int gf=1;

	printf("I am %d years old.\nI have %d girl friends.\n", age, gf);
}

void ex2(void)
{
	printf("123\t456\tapple\t1\t2\n");
	printf("a\tb\tc\td\te\t\n");
	printf("spring\tsummer\tautumn\twinter\n");
}

void ex3(void)
{
	int z=20;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
}

void ex4(void)
{
	char *name="kenshirou tsuge";
	printf("my name is %s.\n",name);

}

void ex5(void){
	int x;

	printf("seisuuwonyuuryokusiro");


	scanf("%d",&x);
	printf("x=%d\n",x);

}

void ex6(void){
	char name[255];

	printf("あなたの名前は何ですか?==>");
	scanf("%s", name);
	printf("%sさん、おっはー\n");

}



int main(void) {

    ex6();
	return 0;
}
