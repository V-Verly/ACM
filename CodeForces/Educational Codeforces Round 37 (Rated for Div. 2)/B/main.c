#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,i,a[1000][2],time;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        time=1;
        i=0;
        while(i<n){
            if(time<a[i][0]) time++;
            else if(a[i][0]<=time&&a[i][1]>=time) {i++;printf("%d ",time++);}
            else {i++;printf("0 ");}
        }
        printf("\n");
    }
    return 0;
}
