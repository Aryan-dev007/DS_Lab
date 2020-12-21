#include "stdio.h"
#include <string.h>

int main() {
    char src[] = "Program";
    char dest[10];

    strcpy(dest, src);
    printf("Destination = %s", dest);
}
