#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int x,int y){
return x>y?x:y;
}
int a[100005][12],dp[100005][12];
int main()
{
    int n,i,j,t;
    while(scanf("%d",&n)!=EOF&&n){
            t=0;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        while(n--){
            scanf("%d%d",&i,&j);
            a[j][i]++;
            t=max(t,j);
        }
        for(i=t;i>=0;i--){
            for(j=0;j<=10;j++){
                if(j==0) dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
                else dp[i][j]=max(max(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1])+a[i][j];
            }
        }
        printf("%d\n",dp[0][5]);
    }
    return 0;
}
