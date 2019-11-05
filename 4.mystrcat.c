#include<stdio.h>
void mystrcat(char *,const char *);
int main()
{
    char source[20],destination[20];
    printf("\nEnter destination string:");
    gets(destination);
    printf("\nEnter source string:");
    gets(source);
    strcat(destination,source);
    printf("\nConcatenated string is:%s",destination);
    return 0;
}
void mystrcat(char *destination,const char *source)
{
    int i,j;
    i=0;
    while(destination[i]!='\0')
    {
        i++;
    }
    for(j=0;source[j]!='\0';j++)
    {
        destination[i]=source[j];
        i++;
    }
    destination[i]='\0';
}


