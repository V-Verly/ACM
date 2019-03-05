#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


const int maxn=2e4+10;

int f[maxn],sz[maxn],o[3],dep[maxn],S,k,cnt,ans=0;
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
    o[dep[u]]++;
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(v==pre||vis[v]) continue;
        dep[v]=(dep[u]+edge[i].w)%3;
        getDeep(v,u);
    }
}

int cal(int u,int D)
{
    cnt=0;dep[u]=D;
    o[0]=o[1]=o[2]=0;
    getDeep(u,0);

    return o[1]*o[2]*2+o[0]*o[0];
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
    scanf("%d",&n);
    memset(head,0xff,sizeof head);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w%3);
    }
    S=f[0]=n,root=0,ans=0;
    getRoot(1,0);
    dfs(root);
    if(!ans) return 0*printf("0/0\n");
    int t=__gcd(ans,n*n);
    printf("%d/%d\n",ans/t,n*n/t);
    return 0;
}
