#include<stdio.h>
#include<string.h>
char *mystrrchr(const char *,int);
int main()
{
    char str[30],ch;
    char *ptr;
    printf("\nEnter a string :");
    gets(str);
    printf("\nEnter character to find:");
    scanf("%c",&ch);
    ptr=mystrrchr(str,ch);
    if(ptr==NULL)
        printf("\nCharacter not found");
    else
        printf("\nCharacter is found at index :%d",ptr-str+1);
    return 0;
}
char *mystrrchr(const char *str,int ch)
{
    int l;
    for(l=0;str[l]!='\0';l++);
    for(l=l-1;l>=0;l--)
    {
        if(str[l]==(char )ch)
            break;
    }
    if(l<0)
        return NULL;
    else
        return &str[l];

}

