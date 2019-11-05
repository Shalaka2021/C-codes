#include<stdio.h>
void mystrncat(char *,const char *,size_t);
int main()
{
    char source[50],destination[50];
    int n;
    printf("\nEnter destination string:");
    gets(destination);
    printf("\nEnter source string:");
    gets(source);
    printf("\nEnter length to concatenate:");
    scanf("%d",&n);
    mystrncat(destination,source,n);
    printf("\nConcatenated string is:%s",destination);
    return 0;
}
void mystrncat(char *destination,const char *source,size_t n)
{
    int i,j;
    for(i=0;destination[i]!='\0';i++);
    for(j=0;j<n&&source[j]!='\0';j++)
    {
        destination[i]=source[j];
        i++;
    }
    destination[i]='\0';
}

