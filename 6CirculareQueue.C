#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

int front = 0, rear = -1, count=0;
char cq[20], item;

void insert(char item) {
	if (count == MAX) {
		printf("Queue Full\n");
	}
	else {
		rear = (rear + 1) % MAX;
		cq[rear] = item;
		count++;
	}
}

void delete() {
	char item;
	if (count == 0) printf("QUEUE empty\n");
	else
	{
		if (front > rear && rear == MAX - 1) {
			front = 0;
			rear = -1;
			count = 0;
		} else {
			item = cq[front];
			front = (front + 1) % MAX;
			count--;
			printf("Deleted Item = %c\n", item);
		}
	}
}


void display() {
	int i;
	printf("Elements of queue are:");
	if (count == 0) {
		printf("Queue is empty\n");
		return;
	}
	for (i = front; i != rear; i = (i + 1) % MAX) {
		printf("%c ", cq[i]);
	}
	printf("%c\n", cq[i]);
}


int main(void) {
	int ch;
	clrscr();
	while (1) {
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch(ch) {
			case 1:
				printf("Element: ");
				flushall();
				scanf("%c", &item);
				insert(item);
				break;
			case 2:
					delete(); break;
			case 3:
					display(); break;
			case 4: return 0;
		}
	}
}
