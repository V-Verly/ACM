#include<stdio.h>

int main(void){
    int k1,k2,k3,flag=0;
    scanf("%d%d%d",&k1,&k2,&k3);
    if(k1==1||k2==1||k3==1) flag=1;
    else if(k1==2&&k2==2||k1==2&&k3==2||k2==2&&k3==2) flag=1;
    else if(k1==3&&k2==3&&k3==3) flag=1;
    else if(k1==2&&k2==4&&k3==4||k1==4&&k2==4&&k3==2||k1==4&k2==2&&k3==4) flag=1;
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
