#include<stdio.h>
#include<stdlib.h>

struct list {
    int data;
    struct list *link;
};
typedef struct list *node;
node *head = NULL;

void insert_rear(node *head) {
    node *temp;
    int item;
    printf("Read the element to be inserted\n");
    scanf("%d", &item);
    temp = (node *) malloc(sizeof(node));
    temp -> data = item;
    temp -> link = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        cur = head;
        while (cur -> link != NULL) {
            cur = cur -> link;
        }
        cur -> link = temp;
    }
}

int countnodes(node *head) {
    node *p;
    p = head;
    count = 0;

    while (p != NULL)  {
        p = p -> link;
        count++;
    }
    return count;
}

int main() {
    int ch, i, n;
    node *head;
    head = NULL;

    do {
        printf("1.Insert Rear\n2.Count\n3.Display\n");
        printf("Read Choice\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Insert selected\n");
                    insert_rear(head);
                    break;

            case 2: n = countnodes(head);
                    printf("Total nodes are %d\n",n);
                    break;

            default: exit(0);


        }
    } while(ch != 2);
}
