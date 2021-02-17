#include<stdio.h>
#include<conio.h>
#include<math.h>

void tower(int n, char source, char destination, char temp) {
	if (n == 0)
		return;
	tower(n-1, source, temp, destination);
	printf("Move disc %d from %c to %c\n", n, source, destination);
	tower(n-1, temp, destination, source);
}

void main() {
	int n;
	clrscr();
	printf("Enter the number of discs: \n");
	scanf("%d", &n);
	tower(n, 'A', 'B', 'C');
	printf("\n\nTotal number of moves are: %d\n ", (int)pow(2,n)-1);
	getch();
}