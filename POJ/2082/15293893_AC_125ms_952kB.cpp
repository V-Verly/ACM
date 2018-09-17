#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn=50000+10;
int w[maxn],h[maxn];
int l[maxn],r[maxn];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        w[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&w[i],&h[i]);
            w[i]+=w[i-1];
        }
        stack<int> st;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            while(!st.empty()&&h[st.top()]>=h[i]) st.pop();
            int res=0;
            if(!st.empty()) res=st.top();
            st.push(i);
            l[i]=(w[i-1]-w[res])*h[i];
        }
        while(!st.empty()) st.pop();
        for(int i=n;i>0;i--)
        {
            while(!st.empty()&&h[st.top()]>=h[i]) st.pop();
            int res=n;
            if(!st.empty()) res=st.top()-1;
            st.push(i);
            r[i]=(w[res]-w[i])*h[i];
        }
        for(int i=1;i<=n;i++)
            ans=max(ans,l[i]+r[i]+(w[i]-w[i-1])*h[i]);
        printf("%d\n",ans);
    }
    return 0;
}
