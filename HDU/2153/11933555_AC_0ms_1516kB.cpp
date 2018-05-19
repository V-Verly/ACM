#include<stdio.h>
#include<string.h>
int main(void)
{
  int n,i,j,t,a[10][10];
  while(~scanf("%d",&n))
  {
      i=0,j=0,t=1;
      memset(a,0,sizeof(a));
      a[0][0]=t;
      while(j<n-1)
      a[i][++j]=++t;
      while(i<n-1)
      a[++i][j]=++t;
      while(j>0)
      a[i][--j]=++t;
      while(i>1)
      a[--i][j]=++t;
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              if(a[i][j]==0) printf("   ");
              else printf("%3d",a[i][j]);
          }
          printf("\n");
      }
  }
}