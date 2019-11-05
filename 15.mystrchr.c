#include<stdio.h>
char *mystrchr(const char *,int);
int main()
{
    char str[30],ch;
    char *ptr;
    printf("\nEnter a string:");
    gets(str);
    printf("\nEnter a character to search:");
    scanf("%c",&ch);
    ptr=mystrchr(str,ch);
    if(ptr==NULL)
       printf("\nCharacter not found");
    else
        printf("\nCharacter is found at index:%d",ptr-str+1);
    return 0;
}
char *mystrchr(const char *str,int ch)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==(char)ch)
            break;
    }
    if(str[i]=='\0')
        return NULL;
    else
        return &str[i];
}

