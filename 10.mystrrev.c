#include<stdio.h>
void mystrrev(char *);
int main()
{
    char str[30];
    printf("\nEnter string:");
    gets(str);
    mystrrev(str);
    printf("\nReverse is:%s",str);
    return 0;
}
void mystrrev(char *str)
{
    int i,l;
    for(l=0;str[l]!='\0';l++);
    i=0;
    while(i<l/2)
    {
        str[i]=str[i]+str[l-1-i];
        str[l-1-i]=str[i]-str[l-1-i];
        str[i]=str[i]-str[l-1-i];
        i++;
    }
}

