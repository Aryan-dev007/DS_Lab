#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 4

int top=-1, flag=0, item, stack[MAX];

void push(int item) {
	if (top == (MAX - 1)) {
		printf("Stack Overflow\n");
	}
	else {
		stack[++top] = item;
	}
}

void pop() {
	int ret;
	if (top == -1) {
		printf("Stack Underflow");
	}
	else {
		ret = stack[top--];
		printf("Popped Element is : %d", ret);
	}
}

void display() {
	int i;
	if (top == -1)
		printf("Stack is Empty\n");
	else {
		for (i = top; i > -1; i--)
			printf("--|%d|--\n", stack[i]);
	}
}

void pallindrome() {
	int i, j;
	for (i = 0, j = top; i <= top; i++, j--) {
		if (stack[i] != stack[j]) {
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		printf("Stack contents are not Pallindrome");
	else
		printf("Stack contents are Pallindrome");
}


void main() {
	int ch;
	clrscr();
	while(1) {
		printf("\n1.push\n2.pop\n3.display\n4.check pallindrome\n5.EXIT\n");
		printf("Enter you choice:  ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("\nEnter item to be pushed:  ");
				scanf("%d", &item);
				push(item);  break;
			case 2: pop();   break;
			case 3: display();   break;
			case 4: pallindrome();   break;
			case 5: exit(0);
		}
	}
}