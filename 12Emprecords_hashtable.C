#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct employee {
	int id;
	char name[15];
};

typedef struct employee EMP;
EMP emp[MAX];
int a[MAX];

int create(int num){
	int key;
	key = num % 10;
	return key;
}

int getemp(EMP emp[], int key) {
	printf("\nEnter emp ID: ");
	scanf("%d", &emp[key].id);
	printf("\nEnter emp name: ");
	flushall();
	gets(emp[key].name);
	return key;
}

void display() {
	int i, ch;
	printf("\n1.Display ALL\n2.Filtered Display");
	printf("\nEnter the choice: ");
	scanf("%d", &ch);
	if (ch == 1) {
		printf("\nThe hash table is: \n");
		printf("HTkey\tEmpID\tEmpName");
		for (i = 0; i < MAX; i++)
			printf("\n%d\t%d\t%s\t", i, emp[i].id, emp[i].name);
	}
	else {
		printf("\nThe hash table is: \n");
		printf("\nHTkey\tEmpID\tEmpName\n");
		for (i = 0; i < MAX; i++){
			if (a[i] != -1) {
				printf("\n%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
				continue;
			}
		}
	}
}

void linear_probe(int key, int num) {
	int flag = 0, i;
	for (i = key + 1; i <= MAX; i++) {
		if (a[i] == -1) {
			a[i] = getemp(emp, i);
			flag = 1;
			break;
		}
	}
	for (i = 0; i < key && flag == 0; i++) {
		if (a[i] == -1) {
			a[i] = getemp(emp, i);
			flag = 1;
			break;
		}
	}
	if (!flag) printf("\nHASH TABLE FULL\n");
}

void main() {
	int num, key, i, ans=1;
	clrscr();
	printf("\nCollision handling by LINEAR PROBING");
	for (i = 0; i < MAX; i++) {
		a[i] = -1;
		printf("%d", a[i]);
	}
	do {
		printf("\nEnter the data: ");
		scanf("%d", &num);
		key = create(num);
		if (a[key] == -1)
			a[key] = getemp(emp, key);
		else {
			printf("Collision Detected\n");
			linear_probe(key, num);
		}
		printf("\nDo you wish to continue? (1/0): ");
		scanf("%d", &ans);
	}while (ans);
	display();
	getch();
}



















