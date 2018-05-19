#include<stdio.h>
#include<string.h>
int mystack[1010];
int main(void){
    int i,t,n,r;
    char s[10],a[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&n,s);
        if(strcmp(s,"FILO")==0)
        {
            int mystack_size=0;
            while(n--)
            {
                scanf("%s",a);
                if(strcmp(a,"IN")==0)
                {
                    scanf("%d",&r);
                    mystack[mystack_size++]=r;
                }
                else
                {
                    if(mystack_size==0) printf("None\n");
                    else  printf("%d\n",mystack[--mystack_size]);
                }
            }
        }
        else
        {
            int mystack_size=0,start=0;
            while(n--)
            {
                scanf("%s",a);
                if(strcmp(a,"IN")==0)
                {
                    scanf("%d",&r);
                    mystack[mystack_size++]=r;
                }
                else
                {
                    if(mystack_size==start) printf("None\n");
                    else  printf("%d\n",mystack[start++]);
                }
            }
        }
    }
   return 0;
}