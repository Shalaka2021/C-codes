#include<stdio.h>
int mystrlen(const char *);

int main()
{
    char str[10];
    printf("\nEnter your string:");
    gets(str);
    printf("\nLength of string is :%d",mystrlen(str));
    return 0;
}
int mystrlen(const char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
       i++;
    }
    return i;
}
