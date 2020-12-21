#include "stdio.h"

int main() {
    char s[10];
    printf("Enter the String: \n");
    /* scanf("%s", s); */
    gets(s);

    printf("%s\n", s);
}
