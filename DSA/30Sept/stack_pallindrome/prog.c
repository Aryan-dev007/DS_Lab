#include<stdio.h>

#define MAX 4

int stack[MAX];
int top = -1, count = 0;

void push(int item) {
    if (top == (MAX - 1)) {
       printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

int pop() {
    int ret;
    if (top == -1) {
       printf("Stack underflow condition\n");
    } else {
        ret = stack[top--];
        printf("Popped elements is %d\n", ret);
    }
    return ret;
}

void pallindrome() {
    int i, temp;
    int flag = 0;

    temp = top;

    for (int i=0,j=top ;i<=top; i++,j--) {
       if (stack[i] != stack[j]) {
           flag = 1;
       }
    }
    if (flag == 0) {
        printf("Stack contents are Palindrome\n");
    } else {
        printf("Stack contents are NOT Palindrome\n");
    }
}

void display() {
    int i;
    printf("The stack contents are: \n");

    if (top == -1) {
        printf("Stack Empty\n");
    }
    else {
        for (i = 0; i <= top ; i++) {
           printf("-----|%d|-----\n",stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch, item, x;
    while (ch != 5){
        printf("---Main MENU---\n");
        printf("1 -> push \n2 -> pop\n3 -> Palindrome\n4 -> Display\n5 -> exit\n");
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
            case 3: pallindrome();
                    break;

            case 4: display();
        }
    }
    return 0;
}
