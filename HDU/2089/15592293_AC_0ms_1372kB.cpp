#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
int a[20];
ll dp[20][2];

ll dfs(int pos,int pre,int state,bool limit)
{
	if(pos==-1) return 1;
	if(!limit&&dp[pos][state]!=-1) return dp[pos][state];
	int up=limit?a[pos]:9;
	ll ans=0;
	for(int i=0;i<=up;i++)
	{
		if(i==4) continue;
		else if(pre==6&&i==2) continue;
		ans+=dfs(pos-1,i,i==6,limit&&i==a[pos]);
	}
	if(!limit) dp[pos][state]=ans;
	return ans;
}

ll solve(ll x)
{
	int pos=0;
	while(x)
	{
		a[pos++]=x%10;
		x/=10;
	}
	memset(dp,0xff,sizeof dp);
	return dfs(pos-1,-1,0,true);
}

int main()
{
	ll l,r;
	while(scanf("%lld%lld",&l,&r)!=EOF&&(l||r))
		printf("%lld\n",solve(r)-solve(l-1));
}
