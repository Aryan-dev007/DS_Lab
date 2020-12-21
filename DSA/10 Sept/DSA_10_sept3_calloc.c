#include<stdio.h>
#include<stdlib.h>

int main() {
    int *p, i, n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    p = calloc(n, sizeof(int));
    if (p==NULL) {
        printf("Insufficient memory\n");
        return 0;
    }

    for (i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }
    for (i=0; i<n; i++) {
        printf("%d", p[i]);
    }
}
