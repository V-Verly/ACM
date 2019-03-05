#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


const int maxn=1e4+10;

int f[maxn],sz[maxn],o[maxn],dep[maxn],S,k,cnt,ans=0;
int head[maxn],tot=0,root;
bool vis[maxn];

struct Edge{int nex,to,w;} edge[maxn<<1];

void add_edge(int u,int v,int w)
{
	edge[tot].nex=head[u];
	edge[tot].to=v;
	edge[tot].w=w;
	head[u]=tot++;
}

void add(int u,int v,int w)
{
    add_edge(u,v,w);
    add_edge(v,u,w);
}

void getRoot(int u,int pre)
{
	f[u]=0,sz[u]=1;	//f表示这个点最大子树的大小，sz是这个点子树大小的和
	for(int i=head[u];~i;i=edge[i].nex)
	{
		int v=edge[i].to;
		if(vis[v]||v==pre) continue;
		getRoot(v,u);
		f[u]=max(f[u],sz[v]);
		sz[u]+=sz[v];
	}
	f[u]=max(f[u],S-sz[u]);
	if(f[u]<f[root]) root=u;
}

void getDeep(int u,int pre)
{
    o[++cnt]=dep[u];
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v==pre||vis[v]) continue;
        dep[v]=dep[u]+edge[i].w;
        getDeep(v,u);
    }
}

int cal(int u,int D)
{
    cnt=0;dep[u]=D;
    getDeep(u,0);
    sort(o+1,o+cnt+1);
    int l=1,r=cnt,res=0;
    while(l<r)
        if(o[l]+o[r]<=k) res+=r-l,l++;
        else r--;
    return res;
}

void dfs(int u)
{
	vis[u]=true,ans+=cal(u,0);
	for(int i=head[u];~i;i=edge[i].nex)
	{
		int v=edge[i].to;
		if(vis[v]) continue;
		ans-=cal(v,edge[i].w);
		S=sz[v],root=0;
		getRoot(v,u);
		dfs(root);
	}
}

int main()
{
    int n,u,v,w;
    while(scanf("%d%d",&n,&k)!=EOF&&n&&k)
    {
        memset(head,0xff,sizeof head);
        memset(vis,0,sizeof vis);
        tot=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        S=f[0]=n;
        root=0;
        ans=0;
        getRoot(1,0);
        dfs(root);
        printf("%d\n",ans);
    }
    return 0;
}
