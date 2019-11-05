#include<stdio.h>
int mystrncmpi(const char *,const char *,size_t);
int main()
{
    char str1[50],str2[50];
    int ch,n;
    printf("\nEnter string 1:");
    gets(str1);
    printf("\nEnter string 2:");
    gets(str2);
    printf("\nEnter length :");
    scanf("%d",&n);
    ch=mystrncmpi(str1,str2,n);
    if(ch==0)
        printf("\nStrings are same");
    else
        printf("\nStrings are different");
    return 0;
}
int mystrncmpi(const char *str1,const char *str2,size_t n)
{
    int k;

        for(k=0;k<n&&str1[k]!='\0'&&str2[k]!='\0';k++)
        {
            if(str1[k]==str2[k]||str1[k]==str2[k]+32||str1[k]==str2[k]-32)
                continue;
            else
                break;
        }

    if(k==n||(str1[k]=='\0'&&str2[k]=='\0'))
        return 0;
    else
        return -1;
}

