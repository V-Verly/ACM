#include<stdio.h>
int main()
{
    char a[3],max,t,min;
    int n,k,i;
    while(gets(a)!=NULL)
    {
if(a[0]>a[1])
max=a[0],min=a[1];
else
max=a[1],min=a[0];
if(a[2]>=max)
t=max,max=a[2];
else if(a[2]<=min)
t=min,min=a[2]; 
else
t=a[2];
printf("%c %c %c\n",min,t,max);
}
}