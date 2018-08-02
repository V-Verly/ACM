#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node
{
    int x,y,z,dep;
    bool operator != (const Node n) {return x!=n.x||y!=n.y||z!=n.z; }
};

void Sort(Node &a)
{
    int num[3];
    num[0]=a.x,num[1]=a.y,num[2]=a.z;
    sort(num,num+3);
    a.x=num[0],a.y=num[1],a.z=num[2];
}

Node root(Node &a)
{
    Node rt=a;
    Sort(rt);
    int s1=rt.y-rt.x,s2=rt.z-rt.y;
    int r;
    while(s1!=s2)
    {
        if(s1>s2)
        {
            r=(s1-1)/s2;
            rt.y-=r*s2;
            rt.z-=r*s2;
        }
        else
        {
            r=(s2-1)/s1;
            rt.x+=r*s1;
            rt.y+=r*s1;
        }
        a.dep+=r;
        Sort(rt);
        s1=rt.y-rt.x,s2=rt.z-rt.y;
    }
    return rt;
}

Node up(Node a,int len)
{
    Sort(a);
    int s1=a.y-a.x,s2=a.z-a.y;
    int r;
    while(len>0)
    {
        if(s1>s2)
        {
            r=(s1-1)/s2;
            if(r>len) r=len;
            a.y-=r*s2;
            a.z-=r*s2;
        }
        else
        {
            r=(s2-1)/s1;
            if(r>len) r=len;
            a.x+=r*s1;
            a.y+=r*s1;
        }
        a.dep-=r;
        len-=r;
        Sort(a);
        s1=a.y-a.x,s2=a.z-a.y;
    }
    return a;
}

int main()
{
    int a,b,c,x,y,z;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        scanf("%d%d%d",&x,&y,&z);
        Node st{a,b,c,0},en{x,y,z,0};
        Node rt1=root(st),rt2=root(en);
        if(rt1!=rt2) printf("NO\n");
        else
        {
            if(st.dep<en.dep) swap(st,en);
            int d=st.dep-en.dep,step;
            st=up(st,d);
            int l=0,r=st.dep;
            while(l!=r)
            {
                int mid=(l+r)>>1;
                if(up(st,mid)!=up(en,mid)) l=mid+1;
                else r=mid;
            }
            step=d+2*l;
            printf("YES\n%d\n",step);
        }
    }
    return 0;
}
