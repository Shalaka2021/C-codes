#include<stdio.h>
void mystrset(char *,int ch);
int main()
{
    char str[30],ch;
    printf("\nEnter a string:");
    gets(str);
    printf("\nEnter a character to set:");
    scanf("%c",&ch);
    mystrset(str,ch);
    printf("\nSet string is:%s",str);
    return 0;
}
void mystrset(char *str,int ch)
{
        int i;
        for(i=0;str[i]!='\0';i++)
            str[i]=(char )ch;
}

