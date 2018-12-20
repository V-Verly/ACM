#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const int maxn=80000+10;
int nex[maxn][100],fail[maxn],en[maxn];

class ACAutomation
{
public:
    int root,L;
    int newnode()
    {
        for(int i=0;i<=96;i++)
            nex[L][i]=-1;
        en[L++]=0;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(char buf[],int p)
    {
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            if(nex[now][buf[i]-32]==-1)
                nex[now][buf[i]-32]=newnode();
            now=nex[now][buf[i]-32];
        }
        en[now]=p;
    }
    void build()
    {
        queue<int> Q;
        fail[root]=root;
        for(int i=0;i<=96;i++)
            if(nex[root][i]==-1)
                nex[root][i]=root;
            else
            {
                fail[nex[root][i]]=root;
                Q.push(nex[root][i]);
            }
        while(!Q.empty())
        {
            int now=Q.front();
            Q.pop();
            for(int i=0;i<=96;i++)
                if(nex[now][i]==-1)
                    nex[now][i]=nex[fail[now]][i];
                else
                {
                    fail[nex[now][i]]=nex[fail[now]][i];
                    Q.push(nex[now][i]);
                }
        }
    }
    bool query(char buf[],int p)
    {
        int len=strlen(buf);
        int now=root;
        set<int> s;
        for(int i=0;i<len;i++)
        {
            now=nex[now][buf[i]-32];
            int tmp=now;
            while(tmp!=root)
            {
                if(en[tmp]) s.insert(en[tmp]);
                tmp=fail[tmp];
            }
        }
        if(s.empty()) return false;
        printf("web %d:",p);
        set<int>::iterator it;
        for(it=s.begin();it!=s.end();it++)
            printf(" %d",*it);
        printf("\n");
        return true;
    }
}AC;

char r[10005];

int main()
{
    int n,t,c=0;
    char s[205];
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        if(c++) printf("\n");
        AC.init();
        for(int i=0;i<n;i++)
        {
            gets(s);
            AC.insert(s,i+1);
        }
        AC.build();
        scanf("%d",&t);
        getchar();
        int res=0;
        for(int i=0;i<t;i++)
        {
            gets(r);
            if(AC.query(r,i+1)) res++;
        }
        printf("total: %d\n",res);
    }
    return 0;
}