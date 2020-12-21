#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, *p;
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    p = malloc(sizeof(int) * n);
    printf("%d", *p);
    if (p == NULL) {
        printf("Insufficient");
        return 0;
    }

    for (int i = 0; i < n; i++)
        scanf("%d", p+i);

    for (int i = 0; i < n; i++)
        printf("%d", *(p+i));
}
