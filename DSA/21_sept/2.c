#include "stdio.h"

/* Declaration */
char string_input[100], pattern[50], replace_with[50], answer[100];
int i, j, c, m, k, flag=0;

void stringmatch() {
    i = m = c = j = 0;

    while (string_input[c] != '\0') {
        // check for \0 in the string for terminating the loop.

        if (string_input[m] == pattern[i]) {
            i++;
            m++;
        // if original string at position 'm' is equal to pattern string at position 'i'
        // then increment both.

            if (pattern[i] == '\0') {
                flag = 1;
                // if pattern string at 'i' is '\0' the search for the next
                // character using for loop
            for (k = 0; replace_with[k] != '\0'; k++, j++)
                answer[j] = replace_with[k];
                i = 0;  // setting i to zero for starting again.
                c = m;
            }
        }

            else {
                answer[j] = string_input[c];
                j++;  // incrementing to next character for answer string.
                c++;     // same as above for orginal string
                m = c;  // replace index of original string with 'c'
                i = 0;
        }
    }
        answer[j] = '\0';  // setting up last character for the answer string.
}


int main() {
    printf("Enter a main String: ");
    gets(string_input);  // string input

    printf("Enter the Patter String: ");
    gets(pattern);   // string input

    printf("Enter the Replace String: ");
    gets(replace_with);     // string input

    stringmatch();

    if (flag == 1 ) {

    printf("Ans String: %s\n", answer); }
    else {
        printf("\n Pattern String not found\n");
    }
    return 0;

}

