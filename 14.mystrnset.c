#include<stdio.h>
void mystrnset(char *,int ,size_t n);
int main()
{
    char str[30],ch;
    int n;
    printf("\nEnter a string:");
    gets(str);
    printf("\nEnter character set:");
    scanf("%c",&ch);
    printf("\nEnter length to set:");
    scanf("%d",&n);
    mystrnset(str,ch,n);
    printf("\nSet string is:%s",str);
    return 0;
}
void mystrnset(char *str,int ch,size_t n)
{
    int i;
    for(i=0;i<n&&str[i]!='\0';i++)
    {
        str[i]=(char )ch;
    }
}

