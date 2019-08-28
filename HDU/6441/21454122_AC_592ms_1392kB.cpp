#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        ll n, a, b, c;
        scanf("%lld%lld", &n, &a);
        if(n == 1) printf("1 %lld\n", a + 1);
        else if(n == 2)
        {
            if(a % 2) b = (a - 1) * (a - 1) / 2 + a - 1, c = b + 1;
            else b = a * a / 4 - 1, c = b + 2;
            printf("%lld %lld\n", b, c);
        }
        else printf("-1 -1\n");
    }
    return 0;
}
