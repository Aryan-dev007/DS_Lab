#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char *S;
    S = malloc(sizeof(char) * 10);

    strcpy(S, "Computer");

    S = realloc(S, 40);
    strcpy(S, "Computer Science and Engineering");

    printf("%s", S);
}
