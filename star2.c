#include<stdio.h>
int main()
{
      int i,j,k,n;
      printf("\nEnter number of rows:");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
            k=1;
            for(j=0;j<2*n-1;j++)
            {
                  if(j>=n-1-i&&j<=n-1+i&&k)
                  {
                        printf("*");
                        k=0;
                  }
                  else
                  {
                        printf(" ");
                        k=1;
                  }
            }
            printf("\n");
      }

      return 0;
}

