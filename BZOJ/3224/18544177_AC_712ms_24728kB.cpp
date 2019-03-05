#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10;

int son[maxn][2],f[maxn],key[maxn],cou[maxn],siz[maxn],root,sz;

void clear(int x)
{
	son[x][0]=son[x][1]=cou[x]=f[x]=siz[x]=key[x]=0;
}

bool get(int x)
{
	return son[f[x]][1]==x;
}

void update(int x)
{
	if(x)
	{
		siz[x]=cou[x];
		if(son[x][0]) siz[x]+=siz[son[x][0]];
		if(son[x][1]) siz[x]+=siz[son[x][1]];
	}
}

void rotate(int x)
{
	int old=f[x],oldf=f[old],whichson=get(x);
	son[old][whichson]=son[x][whichson^1],f[son[old][whichson]]=old;
	son[x][whichson^1]=old,f[old]=x;
	f[x]=oldf;
	if(oldf) son[oldf][son[oldf][1]==old]=x;
	update(old);
	update(x);
}

void splay(int x)
{
	for(int fa;(fa=f[x]);rotate(x))
		if(f[fa]) rotate(get(x)==get(fa)?fa:x);
	root=x;
}

void insert(int x)
{
	if(root==0) {
		sz++;
		son[sz][0]=son[sz][1]=f[sz]=0;
		key[sz]=x;
		cou[sz]=siz[sz]=1;
		root=sz;
		return;
	}
	int now=root,fa=0;
	while(1)
	{
		if(x==key[now])
		{
			cou[now]++;
			update(now);
			update(fa);
			splay(now);
			break;
		}
		fa=now;
		now=son[now][key[now]<x];
		if(now==0)
		{
			sz++;
			f[sz]=fa;
			son[sz][0]=son[sz][1]=0;
			cou[sz]=siz[sz]=1;
			son[fa][key[fa]<x]=sz;
			key[sz]=x;
			update(fa);
			splay(sz);
			break;
		}
	}
}

int find(int x)
{
	int now=root,ans=0;
	while(1)
	{
		if(x<key[now]) now=son[now][0];
		else
		{
			ans+=(son[now][0]?siz[son[now][0]]:0);
			if(x==key[now])
			{
				splay(now);
				return ans+1;
			}
			ans+=cou[now];
			now=son[now][1];
		}
	}
}

int findx(int x)
{
	int now=root;
	while(1)
	{
		if(son[now][0]&&x<=siz[son[now][0]]) now=son[now][0];
		else
		{
			int tmp=(son[now][0]?siz[son[now][0]]:0)+cou[now];
			if(x<=tmp) return key[now];
			x-=tmp;
			now=son[now][1];
		}
	}
}

int pre()
{
	int now=son[root][0];
	while(son[now][1]) now=son[now][1];
	return now;
}

int nex()
{
	int now=son[root][1];
	while(son[now][0]) now=son[now][0];
	return now;
}

void del(int x)
{
	int whatever=find(x);
	if(cou[root]>1)
	{
		cou[root]--;
		update(root);
		return;
	}
	if(!son[root][0]&&!son[root][1])
	{
		clear(root);
		root=0;
		return;
	}
	if(!son[root][0])
	{
		int oldroot=root;
		root=son[root][1];
		f[root]=0;
		clear(oldroot);
		return;
	}
	if(!son[root][1])
	{
		int oldroot=root;
		root=son[root][0];
		f[root]=0;
		clear(oldroot);
		return;
	}
	int leftbig=pre(),oldroot=root;
	splay(leftbig);
	son[root][1]=son[oldroot][1];
	f[son[root][1]]=root;
	clear(oldroot);
	update(root);
}

int main()
{
    int n,op,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&op,&x);
        if(op==1) insert(x);
        if(op==2) del(x);
        if(op==3) printf("%d\n",find(x));
        if(op==4) printf("%d\n",findx(x));
        if(op==5)
        {
            insert(x);
            printf("%d\n",key[pre()]);
            del(x);
        }
        if(op==6)
        {
            insert(x);
            printf("%d\n",key[nex()]);
            del(x);
        }
    }
    return 0;
}
