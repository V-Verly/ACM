#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

char a[maxn],b[maxn],st[maxn];
int nex[maxn],p[maxn];

void getNext()
{
	int len=strlen(b),i=0,j=-1;
	nex[0]=-1;
	for(int i=1;i<len;i++)
    {
        while(j!=-1&&b[i]!=b[j+1]) j=nex[j];
        if(b[i]==b[j+1]) j++;
        nex[i]=j;
    }
}

void KMP()
{
	int n=strlen(a),m=strlen(b);
	getNext();
	int top=0;
	for(int i=0;i<n;i++)
	{
		int j=p[top];
		st[++top]=a[i];
		while(j!=-1&&b[j+1]!=st[top]) j=nex[j];
		if(b[j+1]==st[top]) j++;
		p[top]=j;
		if(p[top]+1==m) top-=m;
	}
	st[top+1]=0;
	puts(st+1);
}

int main()
{
	scanf("%s%s",a,b);
	KMP();
	return 0;
}
