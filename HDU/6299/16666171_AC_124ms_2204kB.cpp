#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
char s[maxn];

struct Section
{
    int l,r;
    bool operator <(const Section &s) const {
        if(l>r) return s.l>s.r?r<s.r:true;
        return s.l<=s.r?l>s.l:false;
    }
}sec[maxn];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            int len=strlen(s),a=0,b=0;
            for(int j=0;j<len;j++)
            {
                if(s[j]=='(') a++;
                else if(a>0) a--,ans++;
                else b++;
            }
            sec[i].l=a,sec[i].r=b;
        }
        sort(sec,sec+n);
        int l=0;
        for(int i=0;i<n;i++)
        {
            int tmp=min(sec[i].r,l);
            l+=sec[i].l-tmp;
            ans+=tmp;
        }
        printf("%d\n",ans*2);
    }
    return 0;
}
