#include<stdio.h>
#include<stdlib.h>

struct list {
    struct list *left;
    int data;
    struct list *right;
};

typedef struct list *node;
node *first = NULL;
node *last = NULL;

void insert_first(node* first) {
    node* temp;
    printf("Read the item\n");
    scanf("%d", &item);
    temp = (node*) malloc(sizeof(node));
    temp -> data = item;
    temp -> right = NULL;
    temp -> left = NULL;

    if (first == NULL) {
        first = temp;
        last = temp;
    }

    temp -> right = first;
    first -> left = temp;
    first = temp;
    return
}

void data_front (node *first) {
    node *cur;
    if (first == NULL) printf("Empty Last");
    else {
        cur = first;
        fist = cur -> right;
        // something
        first -> left = NULL;
        return;
    }
}

int main(void)
{
    int ch;

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
