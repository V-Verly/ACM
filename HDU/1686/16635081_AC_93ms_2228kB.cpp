#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10;
const int maxm=1e4+10;

char a[maxn],b[maxm];
int nex[maxm];

void getNext()
{
	int n=strlen(b),i=0,j=-1;
	nex[0]=-1;
	while(i<n)
	{
		if(j==-1||b[i]==b[j]) nex[++i]=++j;
		else j=-1;
	}
}

int KMP()
{
	int m=strlen(a),n=strlen(b);
	int i=0,j=0,ans=0;
	getNext();
	while(i<m&&j<n)
	{
		if(j==-1||a[i]==b[j]) i++,j++;
		else j=nex[j];
		if(j==n) j=nex[j],ans++;
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",b,a);
		printf("%d\n",KMP());
	}
	return 0;
}
