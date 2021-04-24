#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	char usn[20];
	struct node *next;
};

typedef struct node NODE;
NODE* head;

void countnodes() {
	NODE* p;
	int count;
	p = head;
	while (p != NULL) {
	p = p -> next;
	count++;
	}
	printf("Number of nodes: %d", count);
}

NODE* getnode() {
	NODE* newnode;
	newnode = (NODE*)malloc(sizeof(NODE));
	printf("Enter the data and usn:\n");
	flushall();
	scanf("%d", &newnode -> data);
	flushall();
	gets(newnode -> usn);
	newnode -> next = NULL;
	return newnode;
}

NODE* create() {
	NODE* newnode;
	if (head == NULL) {
		newnode = getnode();
		head = newnode;
	}
	else {
		newnode = getnode();
		newnode -> next = head;
		head = newnode;
	}
	return head;
}

void insert_front() {
	 head = create();
}

NODE* insert_rear() {
	if (head == NULL) create();
	else {
		NODE* p, *newnode;
		newnode = getnode();
		p = head;
		while (p -> next != NULL) {
			p = p -> next;
		}
		p -> next = newnode;
		return newnode;
	}
}

void delete_front() {
	NODE *p;
	p = head;
	head = head -> next;
	free(p);
}

void delete_rear() {
	NODE *p, *q;
	p = head;
	while (p -> next != NULL) {
		q = p;
		p = p -> next;
	}
	free(p);
	q -> next = NULL;
}

void display() {
	NODE* p;
	p = head;
	while (p != NULL) {
		printf("Elements are: \n %d and %s\n", p -> data, p -> usn);
		p = p -> next;
	}
}

void stack() {
	int ch;
	printf("SLL are stack!!\n");
	free(head);
	head = NULL;
	while (1) {
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insert_front(); break;
			case 2: delete_front(); break;
			case 3: display(); break;
			case 4: return;
		}
	}
}

void queue() {
	int ch;
	printf("SLL are queue!!\n");
	free(head);
	head = NULL;
	while (1) {
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insert_rear(); break;
			case 2: delete_front(); break;
			case 3: display(); break;
			case 4: head = NULL; return;
		}
	}
}



int main(void) {
	int ch;
	head = NULL;
	clrscr();
	while (1) {
		printf("1.Create\n2.Insert\n3.Delete\n4.Stack\n5.Queue\n6.Display\n.Exit\n");
		printf("Enter Choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: create(); break;
			case 2: insert_front(); break;
			case 3: delete_front(); break;
			case 4: stack(); break;
			case 5: queue(); break;
			case 6: display(); break;
			case 7: return 0;
		}
	}
}
