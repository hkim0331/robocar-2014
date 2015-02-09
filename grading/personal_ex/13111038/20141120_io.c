/*
 ============================================================================
 Name        : io.c
 Author      : Hitoshi Ninomiya
 Version     : 1.0
 Copyright   : All Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void)
{

	int age=52;
	int gf=3;
	printf( "I am %d years old.\nI have %d friend.\n", age, gf );
}

void ex2(void)
{
    printf("123\t3456\tapple\t1\t2\n");
    printf("1\tb\tc\td\te\t\n");
    printf("spring\tsummer\taoutum\twinter\n");
}

void ex3(yoid)
{
    int z=-1;
    printf("z= %d, %u, %o, %x\n",z,z,z,z);
}

void ex4(void)
{
    char *name="hitoshi ninomiya";
    printf("my name is %s.\n",name);

}

void ex5(void)
{    int x;

     printf("asdfghjkl\n");
     scanf("%d",&x);
     printf("x=%d\n",x);


}

int main(void) {


	ex5();
	return 0;
}
