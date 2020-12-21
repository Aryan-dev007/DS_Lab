#include "stdio.h"

void my_strcpy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    char src[25], dest[25];
    printf("Enter the String\n");
    /* scanf("%s", src); */
    gets(src);

    my_strcpy(dest, src);
    printf("Dest = %s", dest);
}
