/*
 ============================================================================
 Name        : io.c
 Author      : 
 Version     :
 Copyright   : kawano sintaro
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void ex1(void)
{ int age=20;
	int gf=6;

	printf("i am %d years old\nI have %d girl friends.\n" , age,gf);
	}
void ex2(void){
	printf("123\t3456\t67848\taplle\t1\t");
printf("a\tb\tc\td\tb\t");
printf("spring\tsummer\t");


}
void ex3(void){
	int z=20;
	printf("z=%d, %u,%o, %x\n",z,z,z,z);

}
void ex4(void){
	char *name="kawano sintaro";
	printf("my name is %s,\n",name);

}
void ex5(void){
	int x;
	printf("整数をいれろ:");
	scanf("%d",&x);
	printf("your input is%d.\n",x);

}


int main(void) {

	ex5();

	return 0;
}
