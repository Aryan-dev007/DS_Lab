#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

struct employee {
	int id;
	char name[20];
};

typedef struct employee EMP;
EMP emp[MAX];
int a[MAX];

int keygen(int num) {
	int key;
	key = num % MAX;
	return key;
}

int getemp(EMP emp[], int key) {
	printf("Enter Employee ID: ");
	scanf("%d", &emp[key].id);
	printf("Enter name of the Employee:  ");
	flushall();
	gets(emp[key].name);
	return key;
}

void display() {
	int i,ch;

	while (1) {
		printf("1.Display ALL\n2.Filtered Display\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);

		if (ch == 1) {
			printf("\nHTkey\tID\tNAME\n");
			for (i = 0; i < MAX; i++) {
				printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
			}
		}
		else if (ch == 2){
			printf("\nHTkey\tID\tNAME\n");
			for (i = 0; i < MAX; i++) {
				if (a[i] != -1) {
					printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
				}
			}
		}
		else {
			break;
		}
	}
}

void linear_prob(int key) {
	int flag=0, i;
	for (i = key+1; i < MAX; i++) {
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
	if (!flag)
		printf("HASH TABLE FULL\n");
}


int main(void) {
	int key, ans, i, data;
	clrscr();
	for (i = 0; i < MAX; i++) a[i] = -1;
	do {
		printf("Enter Data: ");
		scanf("%d", &data);
		key = keygen(data);
		if (a[key] == -1) {
			a[key] = getemp(emp, key);
		} else {
			printf("Collision Detected\n");
			linear_prob(key);
		}
		printf("Do you want to continue: 0 or 1 -> ");
		scanf("%d", &ans);
	} while (ans == 1);
	display();
	getch();
	return 0;
}
