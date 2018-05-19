#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int D,I,t,n,i,k;
    while(scanf("%d",&t)!=EOF&&t!=-1){
        while(t--){
            scanf("%d%d",&D,&I);
                int k=1;
                for(i=0;i<D-1;i++){
                    if(I%2){
                        k=k*2;
                        I=(I+1)/2;
                    }
                    else{
                        k=k*2+1;
                        I/=2;
                    }
                }
            printf("%d\n",k);
        }
    }
    return 0;
}
