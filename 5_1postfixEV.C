#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>

int expr(int op1, int op2, char symbol) {
	switch (symbol) {
	case '+': return op1 + op2;
	case '-': return op1 - op2;
	case '*': return op1 * op2;
	case '/': return op1 / op2;
	case '$':
	case '^': pow(op1, op2);
	default : return 0;
	}
}


int main(void) {
	int i, top = -1, res = 0, op1 = 0, op2 = 0;
	char s[20], symbol, postfix[20];
	clrscr();
	printf("Enter a valid postfix exp: ");
	flushall();
	scanf("%s", postfix);
	for (i = 0; i < strlen(postfix); i++) {
		symbol = postfix[i];
		if (isdigit(symbol)) s[++top] = symbol - '0';
		else {
			op2 = s[top--];
			op1 = s[top--];
			s[++top] = expr(op1, op2, symbol);
		}
	}
	res = s[top--];
	printf("Required solution: %d", res);
	getch();
	return 0;
}