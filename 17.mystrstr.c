/*#include<stdio.h>
char *mystrstr(const char *,const char *);
int main()
{
    char str1[40],str2[30],*ptr;
    printf("\nEnter a string:");
    gets(str1);
    printf("\nEnter string to find:");
    gets(str2);
    ptr=mystrstr(str1,str2);
    if(ptr==NULL)
        printf("\nString not found");
    else
    {
        printf("\nString found at index :%d",ptr-str1+1);
        printf("\nString is :%s",str2);
    }
    return 0;
}
char *mystrstr(const char *str1,const char *str2)
{
    int i,j;
    for(i=0;str1[i]!='\0';i++)
    {
        for(j=0;str2[j]!='\0';j++)
        {
            if(str1[i]!=str2[j])
                break;
            else
                i++;
        }
        if(str2[j]=='\0')
            break;
    }
    if(str2[j]!='\0')
        return NULL;
    else
    {
        i=i-j;
        return &str1[i];
    }
}


*/
