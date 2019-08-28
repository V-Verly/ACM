#include <bits/stdc++.h>

using namespace std;

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        int p;
        scanf("%d", &p);
        for(int i = 0; i < p; i ++)
            for(int j = 0; j < p; j ++)
                printf("%d%c", (i + j) % p, j == p - 1 ? '\n' : ' ');
        for(int i = 0; i < p; i ++)
            for(int j = 0; j < p; j ++)
                printf("%d%c", i * j % p, j == p - 1 ? '\n' : ' ');
    }
    return 0;
}
