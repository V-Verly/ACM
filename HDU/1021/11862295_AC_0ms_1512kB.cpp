#include <stdio.h>
int main(void){
    long long n;
    while(~scanf("%lld",&n))
    {
        if(n%8==2||n%8==6) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
