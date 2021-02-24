#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i, m, j, c, k, flag=0; 
char ans[100], str[100], pat[50], rep[50];

void stringmatch() {
	 i = m = j = c = 0;
	 while(str[c] != '\0') {
		 if (str[m] == pat[i]) {
			 i++;
			 m++;
			 if (pat[i] == '\0') {
				 flag = 1;
				 for (k = 0; rep[k] != '\0'; k++, j++) ans[j] = rep[k];
				 i = 0;
				 c = m;

			 }
		 }
		 else {
			 ans[j] = str[c];
			 j++;
			 c++;
			 m = c;
			 c = 0;
		 }
	 }

	 ans[j] = '\0';
}

int main() {
	printf("Enter main string: ");
	gets(str);
	printf("Enter pattern string: ");
	gets(pat);
	printf("Enter replace string: ");
	gets(rep);
	stringmatch();
	printf("%s", ans);
}
