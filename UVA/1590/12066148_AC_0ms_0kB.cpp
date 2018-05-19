#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
void binary(int a,int s[]);
int decimal(int s[]);
int main(void){
int n,i,t,address[4],mask[4],ip[4][1005],a[32],b[32],c[32],d[32];
while(~scanf("%d",&n)){
    for(i=0;i<n;i++)
       scanf("%d.%d.%d.%d",&ip[0][i],&ip[1][i],&ip[2][i],&ip[3][i]);
    for(i=0;i<4;i++) sort(ip[i],ip[i]+n);
    for(i=0;i<4;i++)
    {
        binary(ip[i][0],a+8*i);
        binary(ip[i][n-1],b+8*i);
    }
    for(i=0;i<32;i++) if(a[i]!=b[i]) break;
    t=32-i;
    for(i=0;i<32;i++)
    {
        if(i<32-t) {c[i]=a[i];d[i]=1;}
        else {c[i]=0;d[i]=0;}
    }
    for(i=0;i<4;i++) 
    {
        address[i]=decimal(c+i*8);
        mask[i]=decimal(d+i*8);
    }
    printf("%d.%d.%d.%d\n",address[0],address[1],address[2],address[3]);
    printf("%d.%d.%d.%d\n",mask[0],mask[1],mask[2],mask[3]);
    }
    return 0;
}
void binary(int a,int s[]){
int i=7;
while(a>0){
    s[i--]=a%2;
    a/=2;
}
if(i>=0){
for(;i>=0;i--)
s[i]=0;
}
}
int decimal(int s[]){
int i,n=0,t=1;
for(i=7;i>=0;i--)
{
    if(s[i]) n+=t;
    t*=2;
}
return n;
}