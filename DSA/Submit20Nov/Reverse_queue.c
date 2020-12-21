#include<stdio.h>
#include<stdlib.h>

#define MAX 50

/* Stack_start */

int top=-1,stack[MAX];

void push(int val)
{

	if(top==MAX-1)
	{
		printf("\nStack is full!!");
	}
	else
	{
		// printf("\nEnter element to push:");
		// scanf("%d",&val);
		top=top+1;
		stack[top]=val;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("\nStack is empty!!");
	}
	else
	{
		printf("\nDeleted element from STACK is %d",stack[top]);
		top=top-1;
	}
}

void display_stack()
{
	int i;

	if(top==-1)
	{
		printf("\nStack is empty!!");
	}
	else
	{
		printf("\nStack is\n");
		for(i=top;i>=0;--i)
			printf("--|%d|--\n",stack[i]);
	}
}

/* Stack END */
/* """ QUEUE """ */
int queue_array[MAX];
int rear = - 1, front = -1;

void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void insert_rev(int add_item)
{
//    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
 //     printf("Insert the element in queue : ");
 //     scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from QUEUE is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        printf("[");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("]");
        printf("\n");
    }
}

void reverse() {
    // element from queue to stack
    for (int j = front; j <= rear; j++) {
        push(queue_array[front]);
        delete();
    }
    printf("\nPushing Deleted Elements from QUEUE to STACK...\n");

    display_stack();

    // element from stack to queue
    for (int k=top; k>=0; --k) {
        insert_rev(stack[top]);
        pop();
    }
    printf("\n\nInserting popped element from STACK to QUEUE...\n");

    printf("\nReverse ");
    display();
}

/* QUEUE END  */

int main()
{
    int choice;
    while (1)
    {
        printf("Operations For QUEUE: \n");
        printf("1.Insert \n2.Delete \n3.Display \n4.Reverse\n5.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            reverse();
            case 5:
            exit(0);
            default:
            printf("Wrong choice \n");
        }
    }
}


