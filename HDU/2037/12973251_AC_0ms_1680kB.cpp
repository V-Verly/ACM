#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct interval{
int s,e;
};
bool cmp(const interval &a,const interval &b){
if(a.e==b.e) return a.s<b.s;
else return a.e<b.e;
}
int main()
{
    int n,i;
    interval a[1005];
    while(scanf("%d",&n)!=EOF&&n){
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i].s,&a[i].e);
        sort(a,a+n,cmp);
        int ans=0,s,sum=0,p[1005]={0};
        while(sum<n){
            int tmp=-1;
            s=0;
            for(i=0;i<n;i++)
            {
                if(p[i]==0&&a[i].s>=tmp){
                    tmp=a[i].e;
                    sum++;
                    p[i]=1;
                    s++;
                }
            }
            ans=max(ans,s);
        }
        printf("%d\n",ans);
    }
    return 0;
}
