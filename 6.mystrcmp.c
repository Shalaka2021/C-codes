#include<stdio.h>
int mystrcmp(const char *str1,const char *str2);
int main()
{
    char str1[30],str2[30];
    int ch;
    printf("\nEnter string 1:");
    gets(str1);
    printf("\nEnter string 2:");
    gets(str2);
    ch=mystrcmp(str1,str2);
    if(ch==0)
        printf("\nBoth strings are equal");
    else
        printf("\nBoth strings are different");
    return 0;
}
int mystrcmp(const char *str1,const char *str2)
{
    int i;
    for(i=0;str1[i]!='\0'&&str2[i]!='\0';i++)
    {
        if(str1[i]!=str2[i])
            break;
    }
    if(str1[i]=='\0'&&str2[i]=='\0')
        return 0;
    else
        return 1;
}
