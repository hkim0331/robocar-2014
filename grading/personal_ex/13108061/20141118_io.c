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

void ex1(void){

printf("11/22\n Sat.\n12:00\n");
printf("jan\tfeb\tmar\tapr\tmay\n");
printf("1\t23\t456\t7890\n");
}

void ex2(void){
	int x=19;
	int y=1;
			printf("I am %d years old, having %d kids\n", x, y);

}


void ex3(void){
	int z=-1;
	int y=15;
	printf("z= %d, %u, %o, %x\n", z,z,z,z);
	printf("z= %d, %u, %o, %x\n", y,y,y,y);
}

void ex4(void){
char *name="takumi simogama";
	printf()

}

void ex5(void){
	int x;
	char *name[256];
	printf("整数を入力\n");
	scanf("%d",&x);
	printf("あなたの入力は %d\n",x);
	printf("名前は？\n");
	scanf("%s",name);
	printf("%sさん、 %dね\n", name, x);

}

void ex6(void){
int x;
char *name[256];
printf("名前は何？\n");
scanf("%s",name)

}


int main() {
ex5();
	return 0;
}
