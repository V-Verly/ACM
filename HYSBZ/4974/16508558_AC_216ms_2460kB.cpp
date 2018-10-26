#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
int nex[maxn],per[maxn],a[maxn];
bool vis[30];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&per[i]);
        nex[i]=i-per[i];
    }
    a[1]=0;
    nex[0]=-1;
    for(int i=2;i<=n;i++)
    {
        if(nex[i]) a[i]=a[nex[i]];
        else
        {
            memset(vis,0,sizeof vis);
            int k=nex[i-1]+1;
            while(k)
            {
                vis[a[k]]=1;
                k=nex[k-1]+1;
            }
            for(int j=0;j<26;j++)
                if(!vis[j]) {a[i]=j;break;}
        }
    }
    for(int i=1;i<=n;i++)
        printf("%c",a[i]+'a');
    printf("\n");
    return 0;
}
