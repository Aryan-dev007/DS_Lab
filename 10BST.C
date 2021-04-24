#include<stdio.h>
#include<conio.h>

struct BST {
	int data;
	struct BST* left;
	struct BST* right;
};

typedef struct BST NODE;
NODE* node;

NODE* create(NODE* node, int data) {

	if (node == NULL) {
		NODE* temp;
		temp = (NODE*)malloc(sizeof(NODE));
		temp -> data = data;
		temp -> right = temp -> left = NULL;
		return temp;
	}
	else {
		if (data > node -> data)
			node -> right = create(node -> right, data);
		else
			node -> left = create(node -> left, data);
	}
	return node;
}

NODE* search(NODE* node, int data) {
	if (data > node -> data) {
		node -> right = search(node -> right, data);
	}
	else if (data < node -> data) {
		node -> left = search(node -> left, data);
	}
	else {
		printf("Value found:  %d", node -> data);
	}
	return node;
}


void inorder(NODE* node) {
	if (node == NULL) return;
	inorder(node -> left);
	printf("%d", node->data);
	inorder(node -> right);
}

void preorder(NODE* node) {
	if (node == NULL) return;
	printf("%d", node -> data);
	preorder(node -> left);
	preorder(node -> right);
}

void postorder(NODE* node) {
	if (node == NULL) return;
	postorder(node -> left);
	postorder(node -> right);
	printf("%d ", node -> data);
}


int main(void) {
	int ch,n,k,i;
	NODE* root;
	root = NULL;
	clrscr();
	while (1) {
		printf("1.CreateTree\n2.SearchTree\n3.Inorder\n4.Preorder\n5.Postorder\nChoice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter the number of elements: ");
				scanf("%d", &n);
				for (i = 0; i < n; i++) {
					scanf("%d", &k);
					// missed root =
					root = create(root, k);
				}
				break;
			case 2:
					printf("Enter the element to be searched");
					scanf("%d",&k);
					search(root, k);
					break;
			case 3: printf("\n");
					inorder(root); break;
			case 4:
					printf("\n");
					preorder(root); break;
			case 5:
					printf("\n");
					postorder(root); break;
			case 6: exit(0);
		}
	}
	return 0;
}
