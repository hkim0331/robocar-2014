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
int smaller(int x, int y)
{
    if (x < y) {
        return x;
    } else {
        return y;
    }
}
int larger(int x, int y){
	if(x<y){
		return y;
	}
	else{
		return x;
	}
}
int max(int x,int y,int z){
	return larger(x,larger(y,z));
}
int is_normal(int x,int y,int z){

return x*x+y*y==z*z||
		y*y+z*z==x*x||
		z*z+x*x==y*y;
}
int is_prime(int x){
	int i;
	for(i=2;i<x;i++){
		if(x%i==0){
			return 0;
		}
	}


     return 1;
}

int main(void) {
	/*int c;
	c= is_normal(4,5,3);
	if(c==1){
		printf("直角\n");
	}
	else{
		printf("直角でない\n");
	}*/
int i=2;
int count=0;
while(1){
	if(is_prime(i)){
		count+=1;
		if(count==1000){
			printf("1000th prime is %d\n",i);
		}
	}
i +=1;
}

	    return 0;
}
