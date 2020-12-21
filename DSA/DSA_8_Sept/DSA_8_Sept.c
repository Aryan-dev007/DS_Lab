#include<stdio.h>

int main() {
    int a[4] = {5, 10 , 15, 20};
    int *p;
    p = a;

        for (int i = 0; i < 4; i++) {
            printf("%d\t", *p );
            p++; //incrementing address for p
        }

}

