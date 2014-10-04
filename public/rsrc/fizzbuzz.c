/*
 ============================================================================
 Name        : fizzbuzz.c
 Author      : Hiroshi Kimura
 Version     : 0.1
 Copyright   : as you like.
 Description : 対戦型 FizzBuzz ゲーム
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ユーザの反応が LAG 秒より遅いとメッセージを出す。
#define LAG 3

void usage(char *name) {
    printf("usage: %s start end turn\n\n", name);
    printf("start から end まで、コンピュータと FizzBuzz を争う。\n");
    printf("turn=1でコンピュータ先攻。\n");
    printf("turn=2でユーザ先攻。\n");
    printf("反応が遅いと '遅いぞ!' を表示。\n");
    printf("例\n");
    printf("$ fizzbuzz 1 50 1\n");
    printf("1から50まで FizzBuz ゲーム。コンピュータ先攻。\n");
    printf("programmed by hkimura, have fun!\n\n");
    exit(1);
}

// return a char pointer to "1", "2", "fizz", "buzz" or "fizzbuzz".
char *fz(int i) {
    static char ans[10];

    if (i % 15 == 0) {
        return "fizzbuzz";
    } else if (i%3 == 0) {
        return "fizz";
    } else if (i%5 == 0) {
        return "buzz";
    }
    sprintf(ans,"%d",i);
    return ans;
}
// return 0 -- computer won.
// return 1 -- user won.
int fizzbuzz(int from, int to, int turn) {
    int i;
    char answer[10];
    time_t now;

    for (i=from; i<=to; i++) {
        if ( (i+turn) %2 == 0) {
            printf("%s\n",fz(i));
        } else {
            printf("? ");
            now = time(NULL);
            scanf("%s",answer);
            if ((time(NULL)-now) > LAG) {
                printf("遅いぞ!\n");
            }
            if (strcmp(answer,fz(i))==0) {
                continue;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

// $ fizzbuzz from to turn
int main(int argc, char *argv[]) {

    if (argc != 4) {
        usage(argv[0]);
    } else {
        if (fizzbuzz(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]))==0) {
            printf("コンピュータの勝ち。\n");
        } else {
            printf("あんたの勝ち。\n");
        }
    }
    return EXIT_SUCCESS;
}
