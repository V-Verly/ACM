#include <stdio.h>
#include<string.h>
int max(int a,int b)
{
    int t;
    if(a>b) t=a;
    else t=b;
    return t;
}
int main(void){
    int n,a[101][101],b[101][101],i,j,c;
    scanf("%d",&c);
    while(c--)
    {
    scanf("%d",&n);
    memset(a,0,sizeof(a));
        for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
        scanf("%d",&a[i][j]);
        }
        }
        memset(b,0,sizeof(b));
        
        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<=i;j++)
            {
                b[i][j]=a[i][j]+max(b[i+1][j],b[i+1][j+1]);
            }
        }
        printf("%d\n",b[0][0]);
        }
    return 0;
}