#include<stdio.h>
int main(void)
{
  double n,i,j,s;
  while(scanf("%lf",&n)!=EOF&&n!=0)
  {
     s=n;
     for(i=2,j=n-1;i<=n;i++,j--)
         s+=(1/i)*j*2;
     printf("%.2f\n",s);
  }
  return 0;
}