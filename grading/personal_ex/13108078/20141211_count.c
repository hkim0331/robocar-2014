/*
 ============================================================================
 Name        : count.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int count100(int a)
{
	int i;
	for(i=0;i<=10;i++){
		if (a<100){
			break;
		}else{
			a -=100;
		}
	}
    return i;
}

