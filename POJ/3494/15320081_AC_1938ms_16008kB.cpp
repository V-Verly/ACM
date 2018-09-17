#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn=2000+10;
int a[maxn][maxn],l[maxn],r[maxn];

int main()
{
    int n,m,x;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&x);
                if(x) a[i][j]=a[i-1][j]+1;
                else a[i][j]=0;
            }
        }
        int ans=0;

        for(int i=1;i<=n;i++)
        {
            stack<int> st;
            for(int j=1;j<=m;j++)
            {
                while(!st.empty()&&a[i][st.top()]>=a[i][j]) st.pop();
                int res=0;
                if(!st.empty()) res=st.top();
                st.push(j);
                l[j]=(j-1-res)*a[i][j];
            }
            while(!st.empty()) st.pop();
            for(int j=n;j>0;j--)
            {
                while(!st.empty()&&a[i][st.top()]>=a[i][j]) st.pop();
                int res=n;
                if(!st.empty()) res=st.top()-1;
                st.push(j);
                r[j]=(res-j)*a[i][j];
            }
            for(int j=1;j<=m;j++)
                ans=max(ans,l[j]+r[j]+a[i][j]);
        }
        printf("%d\n",ans);

    }
    return 0;
}
