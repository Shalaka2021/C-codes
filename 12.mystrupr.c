#include<stdio.h>
void mystrupr(char *);
int main()
{
    char str[30];
    printf("\nEnter a string:");
    gets(str);
    mystrupr(str);
    printf("\nString in upper case :%s",str);
    return 0;
}
void mystrupr(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>=97&&str[i]<=122)
            str[i]=str[i]-32;
    }
}

