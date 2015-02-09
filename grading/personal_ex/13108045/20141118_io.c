/*
 ============================================================================
 Name        : io.c
 Author      : kurachi
 Version     :1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void ex1(void){
	printf("あああああああああああ\nいいいい\nうううう\n");
	printf("jun\tfeb\tmur\taer\n");
	printf("1\t23\t3456\n");
}
void ex2(void){

	int x=5423;
	int y=765;
	printf("i love him, he is %d years old.our kids are %d 人.\n",x,y);

}
void ex3(void){
	int z=-1;
	int y=15;
	printf("z=%d %u %o %x\n",z,z+1,z,z);
	printf("y=%d %u %o %x \n",z,z,z,z);
}

void ex4(void){
	char *name="masakappo";
	printf("my name is %s.\n",name);
}

void ex5(void){
	int x;
	char name[256];

	printf("x=");
	scanf("%d",&x);
	printf("your name");
	scanf("%s",name);
	printf("Mr,Ms %s, %d years\n",name,x);
}

void ex6(void)
int a;
printf("what year did you born?");
scanf("%d",&a);
printf("you is ")

int main(void){
	//ex1();//
	//ex2();//
	//ex3();//
	//ex4();//
	ex5();
	return 0;
}


