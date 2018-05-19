#include<stdio.h>

char mystack[15], target[15],rail[15];
int n;
int main(void){
    int i,j;
   while(scanf("%d",&n)!=EOF&&n){
           scanf("%s",rail);
           scanf("%s",target);
       i=0,j=0;
       int ans=1,mystack_size=0;
       while(i<n)
       {
           if(rail[j]==target[i]) {i++;j++;}
           else if(mystack_size!=0&&mystack[mystack_size-1]==target[i])
           {mystack_size--;i++;}
           else if(j<n) mystack[mystack_size++]=rail[j++];
           else {ans=0;break;} 
       }
       printf("%s\n",ans?"Yes.":"No.");
       if(ans)
       {i=0,j=0;
           while(i<n)
       {
           if(rail[j]==target[i]) {printf("in\nout\n");i++;j++;}
           else if(mystack_size!=0&&mystack[mystack_size-1]==target[i])
           {printf("out\n");mystack_size--;i++;}
           else if(j<n) {printf("in\n");mystack[mystack_size++]=rail[j++];}
           else {ans=0;break;} 
       }
       }
       printf("FINISH\n");
   }
   return 0;
}