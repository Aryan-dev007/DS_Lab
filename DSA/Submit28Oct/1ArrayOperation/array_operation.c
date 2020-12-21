#include "stdio.h"
#include <stdlib.h>

int a[100], n, elem, pos;

void create () {
    printf("Enter the Size of the Array elements:  ");
    scanf("%d", &n);
    printf("Enter the elements for the  array:  \n");

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}

void display() {
    int i;
    printf("The array elements are: \n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void insert() {
    printf("Enter the position for the new elements:  ");
    scanf("%d", &pos);
    pos = pos - 1;

    printf("Enter the elements to be inserted\n");
    scanf("%d", &elem);

    for (int i = n-1; i >= pos; i--) {
        a[i+1] = a[i];
    }
    a[pos] = elem;
    n = n + 1;
}

void del() {
    printf("Enter the position of the elements to be deleted:  ");
    scanf("%d", &pos);
    pos = pos - 1;
    elem = a[pos];
    for (int i = pos; i < n-1; ++i) {
        a[i] = a[i+1];
    }

    n = n-1;
    printf("\n The deleted elements is = %d\n", elem);

}

int main() {
    int ch;
    do {
        printf("------MENU----------\n");
        printf("1. Create\n2. Display\n3. Insert\n4. Delete\n5. Exit\n");
        printf("Enter your Choice:  ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert();
                    break;
            case 4: del();
                    break;
            case 5: exit(0);
                    break;

            default: printf("\n-------INVALID CHOICE----------\n");
        }
    }while (ch != 5);
}
