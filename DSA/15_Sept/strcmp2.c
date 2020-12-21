#include "stdio.h"

int my_strcmp(char s1[], char s2[]);

int main() {
    int diff;
    char s1[100], s2[100];
    printf("Input the String: ");
    gets(s1);
    printf("Input Another String:  ");
    gets(s2);

    diff = my_strcmp (s1, s2);
    printf("diff -> %d", diff);


}

int my_strcmp (char s1[], char s2[]) {
    int i = 0;
    while (s1[i]==s2[i]) {
        if (s1[i] == '\0' || s2[i] == '\0') {
            break;
        }
        i++;
    }
    return s1[i]-s2[i];
}
