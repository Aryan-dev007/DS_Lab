#include<stdio.h>
#include<conio.h>
#define MAX 4

int ch, front=0, rear=-1, count=0;
char q[MAX], item;

void insert() {
	if (count == MAX)
		printf("\n QUEUE is FULL\n");
	else
	{
		rear = (rear + 1) % MAX;
		q[rear] = item;
		count++;
	}
}

void del() {
	if (count == 0)
		printf("QUEUE is EMPTY\n");
	else {
		if ((front > rear) && (rear == MAX - 1))  {
			front = 0;
			rear = -1;
			count = 0;
		}
		else {
			item = q[front];
			printf("\n Deleted item is: %c", item);
			front = (front + 1) % MAX;
			count--;
		}
	}
}

void display() {
	int i, f = front, r = rear;
	if (count == 0)
		printf("\nQUEUE is EMPTY\n");
	else {
		printf("Contents of the Queue is: \n");
		for (i = f; i != r; i = (i + 1) % MAX) {
			putch(q[i]);
			printf(" ");
		}
		printf("%c\t", q[i]);
	}
}

void main() {
	clrscr();
	do {
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter the choice: ");
		scanf("%d", &ch);
		flushall();
		switch(ch) {
			case 1: printf("Enter the character/ item to be inserted: ");
					item = getche();
					insert();
					break;
			case 2: del(); break;
			case 3: display(); break;
			case 4: exit(0); break;
		}
	}while(ch != 4);
	getch();
}