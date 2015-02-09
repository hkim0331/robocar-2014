/*
 ============================================================================
 Name        : io.c
 Author      : HIROKI ABE
 Version     :1.0
 Copyright   : All Right Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void)
{
	int age =20;
	int gf =3;

	printf("I am %d years old\n I have %d girs friends.\n",age,gf);
}

void ex2(void)
{
  printf("123\t3456\tapple\t11\t2\n");
	printf("a\tb\tc\td\te\t\n")	;
  printf("spring\tsumnmner\tautum\twinter\n");

}
void ex3(void)
{
	int z=-1;
    printf("z=%d,%u,%o,%x\n",z,z,z,z,z);
}
void ex4(void)
{
	char *name="hiroki abe";
   printf("my name is %s.\n",name)};


int main(void) {
	ex4();
	return 0;
}
