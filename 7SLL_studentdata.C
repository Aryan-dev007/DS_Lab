#include<stdio.h>
#include<conio.h>

int MAX = 4, count;
struct student {
	char usn[10];
	char name[30];
	char branch[5];
	int sem;
	char phno[10];
	struct student *next;
};

typedef struct student NODE;
NODE *head;

int countnodes() {
	NODE *p;
	count = 0;
	p = head;
	while (p != NULL) {
		p = p -> next;
		count++;
	}
	return count;
}

NODE* getnode() {
	NODE *newnode;
	newnode = (NODE*)malloc(sizeof(NODE));
	printf("\nEnter USN, Name, Branch, Sem, Ph.NO\n");
	flushall();
	gets(newnode -> usn);
	flushall();
	gets(newnode -> name);
	flushall();
	gets(newnode -> branch);
	flushall();
	scanf("%d", &(newnode -> sem));
	flushall();
	gets(newnode -> phno);
	newnode -> next = NULL;
	return newnode;
}

NODE* display() {
	NODE *p;
	if (head == NULL)
		printf("No Student data\n");
	else {
		p = head;
		printf("\n\n====Student data====\n\n");
		printf("\nUSN\tNAME\tBRANCH\tSEM\tPH.NO\n");
		while(p != NULL) {
			printf("%s\t%s\t%s\t%d\t%s\n",p->usn, p->name, p->branch, p->sem, p->phno);
			p = p->next;
		}
		printf("\nThe no. of nodes in list is: %d", countnodes(head));
	}
	return head;
}

NODE* create() {
	NODE* newnode;
	if (head == NULL) {
		newnode = getnode();
		head = newnode;
	}
	else {
		newnode = getnode();
		newnode->next = head;
		head = newnode;
	}
	return head;
}

void insert_front() {
	if (countnodes(head) == MAX)
		printf("\nList if Full/ Overflow!!");
	else
		head = create();
}

void insert_rear() {
	NODE *p, *newnode;
	p = head;
	if (countnodes(head) == MAX)
		printf("\nList is Full(QUEUE)");
	else {
		if (head == NULL) {
			newnode = getnode();
			head = newnode;
		}
		else {
			newnode = getnode(head);
			while(p -> next != NULL) p = p -> next;
			p -> next = newnode;
		}
	}
}
void insert() {
	int ch;
	do {
		printf("\n1.Insert at FRONT\t2.Insert at REAR\t3.Exit\n");
		printf("\nEnter you choice:  ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insert_front(); break;
			case 2: insert_rear(); break;
			case 3: break;
		}
		display();
	} while (ch != 3);
}


void delete_front() {
	NODE *p;
	if (head == NULL)
		printf("\nList is Empty/Underflow(STACK/QUEUE)\n");
	else {
		p = head;
		head = head -> next;
		free(p);
		printf("\nFront node is deleted\n");
	}
}

void delete_rear() {
	NODE *p, *q;
	p = head;
	if (count == 1) {
		delete_front();
		return;
	}
	while (p -> next != NULL) {
		q = p;
		p = p -> next;
	}
	free(p);
	q -> next = NULL;
	printf("\nLast (end) entry is deleted\n");
}

void del() {
	int ch;
	do {
		printf("\n1.DELETE from FRONT\t2.DELETE from END\t3.EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: delete_front(); break;
			case 2: delete_rear(); break;
			case 3: break;
		}
		display();
	} while(ch != 3);
}

NODE* stack() {
	int ch;
	do {
		printf("\nSSL used as Stack...\n");
		printf("\n1.Insert at Front(PUSH)\t2.Delete from front(POP)\t3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insert_front(); break;
			case 2: delete_front(); break;
			case 3: break;
		}
		display();
	} while(ch != 3);
}

void queue() {
	int ch;
	do {
		printf("SSL used as a QUEUE\n");
		printf("Insert at Rear(INSERT)\t2.Delete from Front(DELETE)\t3.Exit\n");
		printf("\nEnter you choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insert_rear(); break;
			case 2: delete_front(); break;
			case 3: break;
		}
	} while(ch != 3);
}

void main() {
	int ch, i, n;
	head = NULL;
	clrscr();
	printf("\n---Student Database---\n");
	do {
		printf("\n1.Create\t2.Display\t3.Insert\t4.Delete\t5.Stack\t6.Queue\t7.Exit\n");
		printf("Enter your choice:  ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: printf("How many Student database you want to create: ");
					scanf("%d", &n);
					for (i = 0; i < n; i++) create();
					break;

			case 2: display(); break;

			case 3: insert(); break;

			case 4: del(); break;

			case 5: stack(); break;

			case 6: queue(); break;

			case 7: exit(0);
		}
	} while(ch != 7);

}



