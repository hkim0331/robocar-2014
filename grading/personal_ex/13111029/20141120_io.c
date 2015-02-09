/*
 ============================================================================
 Name        : io.c

 Author      : 
 Version     :

 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void)
{
	int age=19;
    int gf=1;
	printf("I am %d years old\nI have %d girl friend.\n", age ,gf);
}

void ex2(void)
{
	printf("123\t3456\tapple\t2\n");
    printf("a\tb\tc\td\te\t\n");
    printf("spring\tsummer\tautum\twinter\n");
}
void ex3(void)
{
	int z=20;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);

}
void ex4(void)
{
	char *name="taisei tanaka";
	printf("my name is %2.\n"name");
}
void ex5(void){
	int x;


	scanf("%d",&x);
	printf("x=%d\n",x)
}
int main(void) {

	ex3();
return 0;
}
