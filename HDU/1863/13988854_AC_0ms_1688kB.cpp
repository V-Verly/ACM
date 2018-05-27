#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int p[105],u[105],v[105],w[105],r[105];
int m,n;
int cmp(const int i,const int j) {return w[i]<w[j];}
int find(int x) {return p[x]==x?x:p[x]=find(p[x]);}
int Kruskal(){
    int ans=0;
    for(int i=0;i<m;i++) p[i]=i;
    for(int i=0;i<n;i++) r[i]=i;
    sort(r,r+n,cmp);
    for(int i=0;i<n;i++)
    {
        int e=r[i];
        int x=find(u[e]);
        int y=find(v[e]);
        if(x!=y) {ans+=w[e];p[x]=y;}
    }
        return ans;
    }
int main()
{
    int i,sum,t;
    while(scanf("%d%d",&n,&m)!=EOF&&n){
        for(i=0;i<n;i++)
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
        sum=0;
        t=Kruskal();
        for(i=0;i<m;i++)
        {
            if(find(p[i])==i) sum++;
        }
        if(sum==1) printf("%d\n",t);
        else printf("?\n");
    }
    return 0;
}