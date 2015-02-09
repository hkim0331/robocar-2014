/*
 ============================================================================
 Name        : hello.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

	int i;

	for (i=1; i<=10; i++) {
		printf(" %d ",i);
		puts("中島さん大好き!!!");
		sleep(1);
	}
		puts("     LOVE !!!!!");

	return EXIT_SUCCESS;
}
