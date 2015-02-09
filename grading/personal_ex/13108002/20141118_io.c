/*
 ============================================================================
 Name        : io.c
 Author      : Tsuyoshi Abe
 Version     :1.0
 Copyright   : All Rights Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



void ex1(void){
	printf("１１/２２\nSat.\nWith Love.\n");
	printf("jan\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t7890\n");




}


void ex2(void){
	int x=21;
	int y=3;
	printf("i am %d years old, having %d kids\n",x,y);

}

void ex3(void){
	int z=-1;
	int y=15;
	printf("z= %d,%u,%o,%x\n",z,z,z,z);
	printf("y= %d,%u,%o,%x\n",y,y,y,y);
}

void ex4(void){
	char *name ="Tsuyoshi Abe";
	printf("my name is %s.\n",name);


}

void ex5(void){
	int x;
char name [256];
	printf("整数を入力して:");
	scanf("%d",&x);
	printf("名前は何?\n");
	scanf("%s",name);
	printf("%sさん,%d　ね\n",name,x);

}

void ex6(void){
	int a,b;

	printf("生まれ年は、何年ですか？\n");
	scanf("%d",a);
	printf("何才ですか？");
	scanf("%d",b);


}


int main(void) {
	ex1();
	ex2();
	ex3();
	ex4();
	ex5();

	return 0;













}
