#include <stdio.h>
int main(void){
int t;
double a,b,c;
scanf("%d",&t);
while(t--){
scanf("%lf%lf%lf",&a,&b,&c);
if (a+b>c&&a+c>b&&b+c>a)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}