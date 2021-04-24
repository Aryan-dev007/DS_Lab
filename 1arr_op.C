#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[100], n, elem, pos;

void create() {
	int i;
	printf("Size of the array:  ");
	scanf("%d", &n);
	printf("Elements of the array are: \n");
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
}

void display() {
	int i;
	printf("Array Elements are: \n");
	for (i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void insert() {
	int i;
	printf("Enter the position of the element:  ");
	scanf("%d", &pos);
	printf("Enter the element:  ");
	scanf("%d", &elem);
	pos -= 1;
	for (i=n-1; i>=pos; i--)
		a[i+1] = a[i];
	a[pos] = elem;
	n += 1;
}

void delete() {
	int i;
	printf("Enter the position of element to be deleted:  ");
	scanf("%d", &pos);
	for (i=pos; i<n; i++)
		a[i-1] = a[i];
	n -= 1;
}

int main(void) {
	int ch;
	clrscr();
	while(1) {
		printf("\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
		printf("Enter your choice:  ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: create(); break;
			case 2: display(); break;
			case 3: insert(); break;
			case 4: delete(); break;
			case 5: return 0;
			default: printf("Invalid Choice\n");
		}
	}
}
