#include<stdio.h>

int mystack[1010];
int n,target[1010];
int main(void){
    int i;
   while(scanf("%d",&n)!=EOF&&n){
      while(1){
       for(i=0;i<n;i++)
       {
           scanf("%d",&target[i]);
           if(target[0]==0) break;
       }
       if(target[0]==0) {
           break;
           }
       i=0;
       int index=1,ans=1,mystack_size=0;
       while(i<n)
       {
           if(index==target[i]) {i++;index++;}
           else if(mystack_size!=0&&mystack[mystack_size-1]==target[i])
           {mystack_size--;i++;}
           else if(index<=n) mystack[mystack_size++]=index++;
           else {ans=0;break;}
           
       }
       printf("%s\n",ans?"Yes":"No");
       }
       printf("\n");
   }
   return 0;
}