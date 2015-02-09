/*
 ============================================================================
 Name        : io.c
 Author      : Eijo Fujiwara
 Version     : 1.0
 Copyright   : All Right Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int ex1(void)
{


int age=52;
int gf=3;

	printf("I am %d years old.\nI have %d kids\.\n ", age, gf);

};


void ex2(void)
{
	printf("123\t3456\tapple\t1\t2\n");

	return 0;
}


void ex3(void)
{
	int z=20;
	printf("z= %d, %u, %o, %x\n", z, z, z, z);
}


void ex4(v0id)
{
	char *name="eijo f";
	printf("my name is %s.\n",name);
}

void ex5(void);
{
	int x;

	scanf("%d",&x);
	printf

}

void ex6(void)
{
	char name[255];

	printf("あなたの名前は何ですか-->");
	scanf("%s", name);
	printf("%sさん、おはようございます。\n");

}


int main(void){
	ex3();
	return 0;
}
