#include<stdio.h>
int main()
{
      int lr,ur;
      int lc,uc;
      int i,j,n,arr[20][20];
      printf("\nEnter a number:");
      scanf("%d",&n);
      lr=lc=0;
      ur=uc=n-1;
      int count=1;
      while(lr<=ur&&lc<=uc)
      {
            for(i=lc;i<=uc;i++)
                  arr[lr][i]=count++;
            lr++;
            for(i=lr;i<=ur;i++)
                  arr[i][uc]=count++;
            uc--;
            for(i=uc;i>=lc;i--)
                  arr[ur][i]=count++;
            ur--;
            for(i=ur;i>=lr;i--)
                  arr[i][lc]=count++;
            lc++;
      }
      for(i=0;i<n;i++)
      {
            for(j=0;j<n;j++)
                  printf("%-3d",arr[i][j]);
            printf("\n");
      }

      return 0;
}

