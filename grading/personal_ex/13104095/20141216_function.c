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

int smaller (int x, int y)
{
	if(x<y){
		return x;
	}else{
		return y;
	}
}

int normal (int x, int y, int z)
{
	return z*z==x*x+y*y ||
			y*y==z*z+x*x ||
			x*x==z*z+y*y;


}

int is_prime(int n){
	int i;

	for(i=2,i<n;i++){
		if(n%i==0){
			return 0;
		}
		return 1;
		}

	if (n%d==)
return
}

int main(void) {
int a=10;
int b=20;
int c=30;

if(normal(a,b,c)){
	printf("直角になる\n");
}else {
	printf("直角にならない\n");
}
}


	return 0;

}
