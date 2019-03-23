#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

struct line
{
    int l,r,pos;
};

bool check(line a,line b)
{
    return b.pos>a.l&b.pos<a.r&&a.pos>b.l&&a.pos<b.r;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        vector<line> col;
        vector<line> row;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a>c) swap(a,c);
            if(b>d) swap(b,d);
            if(a==c)
            {
                col.push_back({b,d,a});
            }
            else if(b==d)
            {
                row.push_back({a,c,b});
            }
        }
        int ans=0;
        for(int i=0;i<col.size();i++)
        {
            for(int j=i+1;j<col.size();j++)
            {
                line a=col[i],b=col[j],c,d;
                for(int u=0;u<row.size();u++)
                {
                    for(int v=u+1;v<row.size();v++)
                    {
                        c=row[u],d=row[v];
                        if(check(a,c)&&check(a,d)&&check(b,c)&&check(b,d)) ans++;
                    }
                }
            }
        }
        printf("Case #%d:\n%d\n",_,ans);
    }
    return 0;
}
