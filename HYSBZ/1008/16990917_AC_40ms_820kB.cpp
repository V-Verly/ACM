/*************************************************************************
	> File Name: 1008.cpp
	> Author: Verly
	> Mail: Verly0206@gmail.com
	> Created Time: 2018年11月13日 星期二 17时06分30秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod=100003;

long long fastpow(long long a,long long n)
{
	long long ans=1,base=a;
	while(n)
	{
		if(n&1) (ans*=base)%=mod;
		(base*=base)%=mod;
		n>>=1;
	}
	return ans;
}

int main()
{
	long long m,n;
	scanf("%lld%lld",&m,&n);
	printf("%lld\n",(fastpow(m,n)-(m*fastpow(m-1,n-1))%mod+mod)%mod);
	return 0;
}