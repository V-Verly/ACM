#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char a[1005][1005];

int main()
{
    int n;
    int mark[1005][26];
    memset(mark,0,sizeof(mark));
    scanf("%d",&n);
    int ans=1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        for(int j=0;j<strlen(a[i]);j++)
        {
            mark[i][a[i][j]-'a']=1;
        }
        bool flag=true;
        for(int j=0;j<i;j++)
        {
            flag=true;
            for(int k=0;k<26;k++)
                if(mark[i][k]!=mark[j][k]) flag=false;
            if(flag) break;
        }
        if(!flag) ans++;
    }
    printf("%d\n",ans);

    return 0;
}
