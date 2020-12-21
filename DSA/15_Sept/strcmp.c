#include<stdio.h>
#include<stdlib.h>
#include <string.h>



int main() {

    char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
    int result1, result2;

    result1 = strcmp(str1, str2);
    result2 = strcmp(str1, str3);

    printf("%d res1\n", result1);
    printf("%d res2\n",result2);
}
