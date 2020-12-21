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
    temp->data = item;
    temp->link = NULL;

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
