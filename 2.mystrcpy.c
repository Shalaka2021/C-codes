#include<stdio.h>
void mystrcpy(char *,const char *);
int main()
{
    char source[20],destination[20];
    printf("\nEnter source sting:");
    gets(source);
    printf("\nSource string is:%s",source);
    mystrcpy(destination,source);
    printf("\nDestination string is:%s",destination);
    return 0;
}
void mystrcpy(char *destination,const char *source)
{
    int i;
    for(i=0;source[i]!='\0';i++)
    {
        destination[i]=source[i];
    }
    destination[i]='\0';
}

