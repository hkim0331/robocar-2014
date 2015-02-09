/*
 ============================================================================
 Name        : function.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int smaller(int x,int y){
	if(x>y){
		return y;
	}
	else{
		return x;
	}
}
int bigger(int x,int y){
	if(x>y){
		return x;
	}
	else{
		return y;
}

int normal(int x,int y,int z){
   return x*x+y*y==z*z||y*y+z*z==x*x||z*z+x*x==y*y;

	}

}

int is-prime(unsigned int n){
	int i;
	for(i=2;i<n;i++){

	}

}

int main(void) {
	int a;
	int b;
	int c;

if(normal(a,b,c)){
	printf("ok\n");
}
else{
	printf("Noooooo!!!\n");
}

}
