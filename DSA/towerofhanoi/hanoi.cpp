#include<stdio.h>
#include<math.h>

void tower(int n, char source, char temp, char destination) {
    if(n==0) return;
    tower(n-1, source, destination, temp);
    printf("Move disc %d from  %c to %c \n",n, source, destination );
    tower(n-1, temp, source, destination);
}

int main(void)
{
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C');
    printf("Total number of moves are: %d\n",(int)pow(2,n)-1);
    return 0;
}
