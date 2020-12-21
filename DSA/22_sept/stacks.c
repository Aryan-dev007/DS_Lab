#include<stdio.h>
#define STACK_SIZE 5

int top=-1, s[10];

void push(int item) {
    if (top == STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s[++top] = item;
}

int pop() {
    if (top == -1) {
        return -1;
    }
        return s[top--];
}

void display() {
    int i;
    if (top == -1) {
        printf("STack empty\n");
        return;
    }
    printf("Stack contents are: \n");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", s[i]);
        }
}


int main(int argc, char *argv[])
{
    int item, x, ch;
    while (ch != 4) {
        printf("1 -> push \n2 -> pop\n3 -> Display\n4 -> Exit\n");
        printf("Your Choice:  ");
        scanf("%d", &ch);


        switch (ch) {
            case 1: printf("Read Item\n");
                    scanf("%d", &item);
                    push(item);
                    break;

            case 2: x = pop();
                    if (x == -1) {
                        printf("Under Flow condition\n");
                        printf("Nothing Removed\n");
                    } else {
                        printf("item removed = %d\n", x);
                    }
            case 3: display();
        }
    }
    return 0;
}




/* DEF - A stack is an ordered list in which insertions and deletions are mad at one end called top. */

/* - In stack the last element inserted is the first one to removed and hence stack is also known as LAST IN FIRST OUT (LIFO) */
/* Insert element - Push Operation */
/* Removing element - Pull Operation */

/* ABSTRACT DATA TYPE: */
/*         Objects of  a finite ordered list of zero or more elements. */


/*         Conditions to be taken care of: */
/*             STACK overflow ====== full stack + push */
/*             STACK underflow ======= empty stack + pop */
