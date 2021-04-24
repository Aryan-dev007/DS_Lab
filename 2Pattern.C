#include<stdio.h>
#include<conio.h>

char stringinp[100], pat[50], repwith[50], ans[100];
int i,j,c,m,k, flag=0;

void stringmatch() {
    i = m = c = j = 0;

    while(stringinp[c] != '\0') {
	if (stringinp[m] == pat[i]) {
	    i++;
	    m++;

		if(pat[i] == '\0')  {
		    flag = 1;

		    for (k = 0; repwith[k] != '\0'; k++,j++) {
			ans[j] = repwith[k];
		    }
			    i=0;
			    c=m;
		}
	}
	else {
		    ans[j] = stringinp[c];
		    j++;
		    c++;
		    m = c;
		    i = 0;
		}
    }
	ans[j] = '\0';
}

int main(void) {
    clrscr();
    printf("Enter the main string:  ");
    scanf("%[^\n]%*c", stringinp);
    getch();
    printf("Enter patter string:  ");
    scanf("%[^\n]%*c", pat);
    printf("Enter replace string: ");
    scanf("%[^\n]%*c", repwith);
    stringmatch();

    if (flag == 1)
	printf("Ans String: %s\n", ans);
    else
	printf("Pattern String not found\n");

    getch();

    return 0;
}
