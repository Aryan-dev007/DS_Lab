#include<stdio.h>
#include<conio.h>

struct BST {
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST NODE;

NODE *node;

NODE* createtree(NODE* node, int data) {
	if (node == NULL){
		NODE *temp;
		temp = (NODE*)malloc(sizeof(NODE));
		temp -> data = data;
		temp -> left = temp -> right = NULL;
		return temp;
	}
	if (data < (node -> data)) node -> left = createtree(node -> left, data);
	else if (data > node -> data) node -> right = createtree(node -> right, data);
	return node;
}

NODE *search(NODE* node, int data) {
	if (node == NULL) printf("Element not found\n");
	else if (data < node -> data) node -> left = search(node -> left, data);
	else if (data > node -> data) node -> right = search(node -> right, data);
	else printf("\nElement found is: %d", node -> data);
	return node;
}

void inorder(NODE *node) {
	if (node != NULL){

		inorder(node -> left);
		printf("%d\t", node->data);
		inorder(node -> right);
	}
}

void preorder(NODE *node) {
	if (node != NULL) {
		printf("%d\t", node -> data);
		preorder(node -> left);
		preorder(node -> right);
	}
}

void postorder(NODE *node) {
	if (node != NULL) {
		postorder(node -> left);
		postorder(node -> right);
		printf("%d\t", node -> data);
	}
}

void main() {
	int data, ch, i, n;
	NODE *root = NULL;
	clrscr();
	while (1) {
		printf("\n1.Insertion in Binary Search Tree");
		printf("\n2.Search Element in Binary Search Tree");
		printf("\n3.Inorder\n4.Preorder\n5.PostOrder\n6.Exit\n");
		printf("Enter your choice:  ");
		scanf("%d", &ch);
		switch (ch) {
			case 1: printf("\nEnter N value:  ");
					scanf("%d", &n);
					printf("Enter values to create BST\n");
					for (i=0; i<n; i++) {
						scanf("%d", &data);
						root = createtree(root, data);
					}
					break;
			case 2:
					printf("Enter the element to be searched: ");
					scanf("%d", &data);
					root = search(root, data);
					break;
			case 3: printf("Inorder Transversal\n");
					inorder(root);
					break;
			case 4: printf("Pre-order Transversal\n");
					preorder(root);
					break;
			case 5: printf("Post-order Transversal\n");
					postorder(root);
					break;
			case 6: exit(0);
			default: printf("\nInvalid INPUT\n");
		}
	}
	getch();
}