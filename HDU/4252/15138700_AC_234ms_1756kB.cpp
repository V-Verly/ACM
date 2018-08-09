#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn=1e5+10;
int a[maxn],st[maxn];

int main()
{
    int n,count=0;
    while(scanf("%d",&n)!=EOF)
    {
        int res=0,top=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            while(top&&st[top-1]>a[i])
            {
                top--;
                res++;
            }
            if(a[i]!=0&&(top==0||st[top-1]<a[i]))
                st[top++]=a[i];
        }
        printf("Case %d: %d\n",++count,res+top);
    }
    return 0;
}
