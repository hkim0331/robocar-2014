/*
 ============================================================================
 Name        : io.c
 Author      : 坂口貴哉
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ex1(void){
	printf("11/22\nSat.\n12:00\nwith love.\n");
	printf("jat\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t7890\n");
}
void ex2(void){
	int x=20;
	int y=3;
	printf("i am %d years old, have %d kids.\n",x,y);
}
void ex3(void){
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n",z,z,z,z);
	printf("y= %d, %u, %o, %x\n",y,y,y,y);
}
void ex4(void){
	char *name="takaya sakaguchi"
}
void ex5(void){
	int x;
	char name[256];

	printf("整数を入力してね:");
	scanf("%d", &x);
	printf("名前はなーに？:");
	scanf("%s",name);
	printf("%sさん、 %dね♂\n",name,x);
}
void ex6(void){
	int x;
	char name[256];

	printf("名前はなに？");
	scanf("%s",name);
	printf("生まれた年は？");
	scanf("%d",x)
}
int main(void){

	//ex1();
	//ex2();
	//ex3();
	//ex4()
	//ex5();
	return 0;
}
