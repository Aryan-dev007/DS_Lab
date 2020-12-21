#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node * next;
};
typedef struct node Node;

struct list {
  Node * head;
};
typedef struct list List;

Node * createnode(int data);

Node * createnode(int data){
  Node * newNode = malloc(sizeof(Node));
  if (!newNode) {
    return NULL;
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

List * makelist(){
  List * list = malloc(sizeof(List));
  if (!list) {
    return NULL;
  }
  list->head = NULL;
  return list;
}

void display(List * list) {
  Node * current = list->head;
  if(list->head == NULL)
    return;

  for(; current != NULL; current = current->next) {
    printf(" %d -> ", current->data);
  }
  printf("NULL\n");
}

void add(int data, List * list){
  Node * current = NULL;
  if(list->head == NULL){
    list->head = createnode(data);
  }
  else {
    current = list->head;
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = createnode(data);
  }
}

void delete(int data, List * list){
  Node * current = list->head;
  Node * previous = current;
  while(current != NULL){
    if(current->data == data){
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void reverse(List * list){
  Node * reversed = NULL;
  Node * current = list->head;
  Node * temp = NULL;
  while(current != NULL){
    temp = current;
    current = current->next;
    temp->next = reversed;
    reversed = temp;
  }
  list->head = reversed;
}


int main(void){
  List * list = makelist();

  while (1){
    int t;
    printf("1.Insert \n2.Delete Element \n3.Display \n4.Reverse \n5.Quit \n");
    printf("Enter your Choice: ");
    scanf("%d", &t);
        switch (t)
        {
            case 1:
            printf("Enter value to be entered:  ");
            int n;
            scanf("%d", &n);
            add(n, list);
            break;
            case 2:
            printf("Enter the number to be deleted: ");
            int d;
            scanf("%d", &d);
            delete(d, list);
            break;
            case 3:
            display(list);
            break;
            case 4:
            reverse(list);
            display(list);
            case 5:
            exit(0);
            default:
            printf("Wrong choice \n");
        }

  }
  return 0;
}
