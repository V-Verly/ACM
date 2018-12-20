#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

static const char b64[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const int maxn=50000+10;

map<char,int> mp;

int n;
unsigned char str[5000+10],enstr[5000+10];

int decode()
{
    int len=0,x=0,p=0;
    for(int i=0;enstr[i]&&enstr[i]!='=';i++)
    {
        len+=6,x=(x<<6)|mp[enstr[i]];
        if(len>=8) {
            str[p++] = (x >> (len - 8)) & 0xff;
            len -= 8;
        }
    }
    return p;
}

class ACAutomation
{
public:
    int nex[maxn][256],fail[maxn],en[maxn],vis[maxn];
    int root,L;
    int newnode()
    {
        for(int i=0;i<256;i++)
            nex[L][i]=-1;
        en[L++]=0;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(unsigned char buf[],int len,int key)
    {
        int now=root;
        for(int i=0;i<len;i++)
        {
            if(nex[now][buf[i]]==-1)
                nex[now][buf[i]]=newnode();
            now=nex[now][buf[i]];
        }
        en[now]=key;
    }
    void build()
    {
        queue<int> Q;
        fail[root]=root;
        for(int i=0;i<256;i++)
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
            for(int i=0;i<256;i++)
                if(nex[now][i]==-1)
                    nex[now][i]=nex[fail[now]][i];
                else
                {
                    fail[nex[now][i]]=nex[fail[now]][i];
                    Q.push(nex[now][i]);
                }
        }
    }
    int query(unsigned char buf[],int len)
    {
        int now=root;
        int res=0;
        memset(vis,0,sizeof vis);
        for(int i=0;i<len;i++)
        {
            now=nex[now][buf[i]];
            int tmp=now;
            while(tmp!=root)
            {
                if(en[tmp]) vis[en[tmp]]=true;
                tmp=fail[tmp];
            }
        }
        for(int i=1;i<=n;i++) if(vis[i]) res++;
        return res;
    }
}AC;

int main()
{
    for(int i=0;i<64;i++) mp[b64[i]]=i;
    int m,len;
    while(scanf("%d",&n)!=EOF)
    {
        AC.init();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",enstr);
            len=decode();
            AC.insert(str,len,i);
        }
        AC.build();
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",enstr);
            len=decode();
            printf("%d\n",AC.query(str,len));
        }
        printf("\n");
    }
    return 0;
}
