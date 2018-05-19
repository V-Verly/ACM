#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[4][100][100],n;

int cal(int k)
{
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if((i+j)%2==0&&!a[k][i][j]) ans++;
            else if((i+j)%2&&a[k][i][j]) ans++;
        }
    return ans;
}

int main()
{
    int i,j,k,s[4];
    scanf("%d",&n);
    for(k=0;k<4;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%1d",&a[k][i][j]);
    for(k=0;k<4;k++)
        s[k]=cal(k);
    sort(s,s+4);
    int sum=s[0]+s[1]+2*n*n-s[2]-s[3];
    printf("%d\n",sum);
    return 0;
}
