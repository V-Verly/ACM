#include <cstdio>
#include <cmath>
using namespace std;

bool prime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return false;
	return true;
}

int main()
{
	int n,count=0;
	while(scanf("%d",&n)!=EOF&&n>0)
	{
		printf("%d: ",++count);
		if(n==1||n==2) {printf("no\n");continue;}
		printf("%s\n",prime(n)?"yes":"no");
	}
	return 0;
}