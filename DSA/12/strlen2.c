#include "stdio.h"
#include <string.h>

int my_strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i ++;
    }
    return i;
}

int main() {
    char s[25];
    int i;
    printf("Enter the String\n");
    gets(s);

    i = my_strlen(s);
    printf("len = %d", i);
}
