#include <stdio.h>
#define EOD (-1)
int stack[64];
int p;

void init(void)
{
    p=0;
}

int push(int n)
{
    stack[p]=n;
    p++;
    return n;
}

int pop(void)
{
    p--;
    if (p<0) {
        return EOD;
    } else {
        return stack[p];
    }
}

void tobase(int n)
{
    int mask;
    int i;

    init();
    mask=1;
    for (i=0;i<32;i++) {
        push( (n & mask)!=0 );
        mask = (mask << 1);
    }
    while ((i=pop())!=EOD) {
        printf("%i",i);
    }
    printf("\n");

}

int main(int argc, char *argv[])
{
    int i;

    printf("sizeof(int):%lu\n", sizeof(int));
    while (scanf("%i",&i)!=EOF) {
        if (i<0) {
            printf("input is negative: %i\n",i);
        }
        tobase(i);
    }
    return 0;
}
