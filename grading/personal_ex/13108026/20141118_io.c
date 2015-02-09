/*
 ============================================================================
 Name        : io.c
 Author      : Masaki Ohno
 Version     :1.0
 Copyright   :All Right Reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void ex1(void){
	printf("11/22\n.12時\n.love\n");
	printf("jan\tfeb\tmar\tapr\tmay\n");
	printf("1\t23\t456\t7890\n");
}
void ex2(){
	int x=21;
	int y=3;
	printf("I am %d years old,having %d kids\n",x,y);


}
void ex3(){

	short z=-1;
	int y=15;
	printf("z=%d,%u,%o,%x\n",z,z,z,z);
	printf("y=%d,%u,%o,%x\n",y,y,y,y);
}
void ex4(){
	char *name="Masaki Ohno";
	printf("my name is %s\n",name);
}
void ex5(){
	int x;
	char name[256];
	printf("prease input integer:");
	scanf("%d",&x);
	printf("名前は何？:");
	scanf("%s",name);
	printf("%sさん、%dですね\n",name,x);
}
void ex6(){
		int x;
		char name[256];
		printf("あなたの名前は何ですか？:");
		scanf("%s",&name);
		printf("名前は何？:");
		scanf("%d",x);
		printf("%sさん、%dですね\n",name,x);

}
int main(void) {
	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	ex6();
	return 0;
}
