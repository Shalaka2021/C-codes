#include<stdio.h>
void mystrlwr(char *);
int main()
{
    char str[20];
    printf("\nEnter a string:");
    gets(str);
    mystrlwr(str);
    printf("\nString in lower case is:%s",str);
    return 0;
}
void mystrlwr(char *str)
{
    int i;

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>=65&&str[i]<=90)
            str[i]=str[i]+32;
    }
}

