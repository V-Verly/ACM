#include <stdio.h>
int main(void){
    int y,t,i,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&y,&n);
        i=0;
        while(i<n)
        {
            if((y%4==0&&y%100!=0)||y%400==0)
            i++;
            y++;
        }
        printf("%d\n",y-1);
    }
    return 0;
}
