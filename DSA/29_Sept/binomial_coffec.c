#include "stdio.h"

int fact(int n) {
    if(n==1) return 1;
    return n * fact(n-1);
}

int main(int argc, char *argv[])
{
    int n, r, ncr;
    printf("Enter N and R\n");
    scanf("%d %d", &n, &r);

    ncr = fact(n) / (fact(n-r)* fact(r));

    printf("Binomial Coffecient =  %d\n", ncr);
    return 0;
}
