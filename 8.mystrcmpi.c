#include<stdio.h>
int mystrcmpi(const char *,const char *);
int main()
{
    char str1[50],str2[50];
    int ch;
    printf("\nEnter string 1:");
    gets(str1);
    printf("\nEnter string 2:");
    gets(str2);
    ch=mystrcmpi(str1,str2);
    if(ch==0)
        printf("\nStrings are same");
    else
        printf("\nStrings are different");
    return 0;
}
int mystrcmpi(const char *str1,const char *str2)
{
    int k;
    for(k=0;str1[k]!='\0'&&str2[k]!='\0';k++)
    {
        if((str1[k]==str2[k])||(str1[k]==str2[k]+32)||(str1[k]==str2[k]-32))
            continue;
        else
            break;
    }

    if(str1[k]=='\0'&&str2[k]=='\0')
        return 0;
    else
        return -1;
}
