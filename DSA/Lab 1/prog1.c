#include<stdio.h>
#include<stdlib.h>

int a[100], n, elem, pos;

void create() {
    printf("\n Enter the size of array elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}


void insert() {
    printf("Enter the position for the new elements\n");
    scanf("%d", &pos);

    pos = pos - 1;

    printf("Enter the element to be inserted\n");
    scanf("%d", &elem);


    for (int i = n; i<= pos; i--) {
    a[i+1] = a[i];
    }

    a[pos] = elem;
    n += 1;
}

void display() {
    int i;
    printf("\n The array elemeents are: \n");

    for (int i=0; i<n; i++) {
        printf("%d\t", a[i]);
    }
}

void del() {
    printf("Enter the position of the element to be deleted\n");

    scanf("%d", &pos);

    pos = pos - 1;
    elem = a[pos];

    for (int i = pos; i < n; i++) {
        a[i] = a[i+1];
    }
    n = n - 1;
    printf("The deleted elements is %d\n", elem);
}
int main() {
    int ch;
    do {
        printf("\n---Menu---\n");
        printf("1. Create\n 2. Display\n 3. Insert\n 4.Delete\n 5. Exit\n");
        printf("\n Enter you choice: ");
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

            default: printf("\n Invalid Input\n");
                     break;
        }
    }while (ch != 5);
}

