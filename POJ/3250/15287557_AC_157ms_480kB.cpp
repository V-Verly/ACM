#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn=8e4+10;
int a[maxn];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        stack<int> st;
        long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&a[st.top()]<a[i]) st.pop();
            long long res=n-1;
            if(!st.empty()) res=st.top()-1;
            //printf("*%d\n",res-i);
            st.push(i);
            ans+=res-i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
