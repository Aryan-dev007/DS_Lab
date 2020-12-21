/* Recursion = Function calling itself. */

// Factorial Using Recursion.
//

#include "stdio.h"

int fact (int n) {
    if(n==1 || n==0)
        return 1;

    return n*fact(n-1);
}

int main(int argc, char *argv[])
{
    int n;
    printf("Enter the Value\n");
    scanf("%d", &n);

    printf("Solution --> %d\n", fact(n));

    return 0;
}
