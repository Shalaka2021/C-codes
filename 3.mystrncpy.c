#include<stdio.h>
void mystrncpy(char *,const char *,size_t);
int main()
{
    int n;
    char source[30],destination[30];
    printf("\nEnter the string:");
    gets(source);
    printf("\nEnter number length of string to be copied:");
    scanf("%d",&n);
    printf("\nSource string is:%s",source);
    mystrncpy(destination,source,n);
    printf("\nDestination string is:%s",destination);
    return 0;
}
void mystrncpy(char *destination,const char *source,size_t n)
{
    int i;
    for(i=0;i<n&&source[i]!='\0';i++)
    {
        destination[i]=source[i];
    }
    destination[i]='\0';
}

