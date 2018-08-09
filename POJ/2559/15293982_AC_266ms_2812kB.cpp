#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn=1e6+10;
 __int64 a[maxn];
 __int64 l[maxn],r[maxn];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        stack<int> st;
         __int64 ans=0;
        for(int i=1;i<=n;i++)
        {
            while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
            int res=0;
            if(!st.empty()) res=st.top();
            st.push(i);
            l[i]=(i-1-res)*a[i];
        }
        while(!st.empty()) st.pop();
        for(int i=n;i>0;i--)
        {
            while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
            int res=n+1;
            if(!st.empty()) res=st.top();
            st.push(i);
            r[i]=(res-i-1)*a[i];
        }
        for(int i=1;i<=n;i++)
            ans=max(ans,l[i]+r[i]+a[i]);
        printf("%I64d\n",ans);
    }
    return 0;
}
