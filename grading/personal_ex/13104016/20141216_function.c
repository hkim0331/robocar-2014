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

int i=2;
int count=0;
int smaller(int x, int y)
{
	if(x<y){
		return x;
	}else{
		return y;
	}
}
int sub(int x,int y,int z){
	return x*x+y*y==z*z;

}
int is_normal(int x, int y, int z)
{
	return sub(x,y,z)||sub(y,z,x)||sub(z,x,y);
}
int is_prime(unsigned int n)
{
	int i;

	for(i=2;i<n;i++){
		if(n%i== 0){
			return 0;
		}else{;
	}
		return 1;
	}
int main(void)
	{
		unsigned int i=1;
				while(1){
					if(is_prime(i)){
						printf("%u is prime\n",i);
					}else{
i++;
					}

				}
		return 0;
	}
