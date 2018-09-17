#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[300];
int pos[300][300];

void show(int l,int r)
{
    if(l>r||l<0||r<0) return;
    else if(l==r)
    {
        if(s[l]=='('||s[l]==')')
            printf("()");
        else
            printf("[]");
    }
    else if(pos[l][r]==-1)
    {
        printf("%c",s[l]);
        show(l+1,r-1);
        printf("%c",s[r]);
    }
    else
    {
        show(l,pos[l][r]);
        show(pos[l][r]+1,r);
    }
}

int main()
{
    int dp[300][300];
    while(gets(s)!=NULL)
    {
        int n=strlen(s);
        memset(dp,0,sizeof(dp));
        for(int k=1;k<n;k++)
        {
            for(int l=0;l<n;l++)
            {
                int r=l+k;
                if(s[l]=='('&&s[r]==')'||s[l]=='['&&s[r]==']')
                {
                    dp[l][r]=dp[l+1][r-1]+2;
                    pos[l][r]=-1;
                }
                for(int mid=l;mid<r;mid++)
                {
                    if(dp[l][mid]+dp[mid+1][r]>=dp[l][r])
                    {
                        dp[l][r]=dp[l][mid]+dp[mid+1][r];
                        pos[l][r]=mid;
                    }
                }
            }
        }
        show(0,n-1);
        printf("\n");
    }
    return 0;
}
