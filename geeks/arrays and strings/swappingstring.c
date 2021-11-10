//swap string literal
#include<stdio.h>

/* Swaps strings by swapping pointers */
void swap1(char **str1_ptr, char **str2_ptr) //whats this?
//how does scope work when it comes to pointer variables and pointers.
{
    char *temp = *str1_ptr;
    *str1_ptr = *str2_ptr;
    *str2_ptr = temp;
}

int main()
{
    char *str1 = "geeks";
    char *str2 = "forgeeks";
    swap1(&str1, &str2);
    printf("str1 is %s, str2 is %s", str1, str2);
    getchar();
    return 0;
}


//swap character array
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Swaps strings by swapping data*/
void swap2(char *str1, char *str2)
{
    char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    free(temp);
}

int main()
{
    char str1[10] = "geeks";
    char str2[10] = "forgeeks";
    swap2(str1, str2);
    printf("str1 is %s, str2 is %s", str1, str2);
    getchar();
    return 0;
}
