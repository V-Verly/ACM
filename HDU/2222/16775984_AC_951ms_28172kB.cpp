#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=5e5+10;
char s[maxn<<1];

class ACAutomation
{
public:
    int nex[maxn][26],fail[maxn],en[maxn];
    int root,L;
    int newnode()
    {
        for(int i=0;i<26;i++)
            nex[L][i]=-1;
        en[L++]=0;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(char buf[])
    {
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            if(nex[now][buf[i]-'a']==-1)
                nex[now][buf[i]-'a']=newnode();
            now=nex[now][buf[i]-'a'];
        }
        en[now]++;
    }
    void build()
    {
        queue<int> Q;
        fail[root]=root;
        for(int i=0;i<26;i++)
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
            for(int i=0;i<26;i++)
                if(nex[now][i]==-1)
                    nex[now][i]=nex[fail[now]][i];
                else
                {
                    fail[nex[now][i]]=nex[fail[now]][i];
                    Q.push(nex[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        int len=strlen(buf);
        int now=root;
        int res=0;
        for(int i=0;i<len;i++)
        {
            now=nex[now][buf[i]-'a'];
            int tmp=now;
            while(tmp!=root)
            {
                res+=en[tmp];
                en[tmp]=0;
                tmp=fail[tmp];
            }
        }
        return res;
    }
}AC;

int main()
{
    int t,n;
    char a[55];
    scanf("%d",&t);
    while(t--)
    {
        AC.init();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",a);
            AC.insert(a);
        }
        AC.build();
        scanf("%s",s);
        printf("%d\n",AC.query(s));
    }
    return 0;
}