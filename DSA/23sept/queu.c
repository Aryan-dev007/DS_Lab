/* A queue is a ordered list in which insertions (additions, pushed) and deletions (removal, pops) take place at different ends. */

/* FIFO */
/* First IN First OUT */
#include "stdio.h"
#include<stdlib.h>

# define MAX_QUEUE_SIZE 100
typedef struct {
    int key;
}element;
element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

void addq(element item) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("QUEUE FULL\n");
        exit(EXIT_FAILURE);
    }
    queue[++rear] = item;
}


element deleteq(){
    if (front == rear) {
        printf("QUEUE is EMPTY\n");
        exit(EXIT_FAILURE);
    }
    return queue[++front];
}



int main() {
}
