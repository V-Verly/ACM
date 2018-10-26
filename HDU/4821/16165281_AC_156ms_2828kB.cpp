#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;

const int maxn=1e5+10;
const int seed=31;

ull base[maxn],h[maxn];
map <ull,int> hashmap;
char s[maxn];

ull gethash(int l,int r) {return h[r]-h[l-1]*base[r-l+1]; }

int main()
{
    int m,l,len;
    base[0]=1;
    for(int i=1;i<maxn;i++)
        base[i]=base[i-1]*seed;
    while(scanf("%d%d",&m,&l)!=EOF)
    {
        scanf("%s",s+1);
        len=strlen(s+1);
        for(int i=1;i<=len;i++)
            h[i]=h[i-1]*seed+s[i]-'a';
        int cnt=0;
        for(int i=1;i<=l&&i+m*l<=len;i++)
        {
            hashmap.clear();
            for(int j=i;j<i+m*l;j+=l)
                hashmap[gethash(j,j+l-1)]++;
            if(hashmap.size()==m) cnt++;
            for(int j=i;j<=len-m*l-l+1;j+=l)
            {
                ull tmp=gethash(j,j+l-1);
                hashmap[tmp]--;
                if(!hashmap[tmp]) hashmap.erase(tmp);
                hashmap[gethash(j+m*l,j+m*l+l-1)]++;
                if(hashmap.size()==m) cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
