//qaly.cpp
#include<cstdio>
int main(){
    int n;
    double sum, a,b;
    scanf("%d",&n);
    while(n--){
        scanf("%lf%lf",&a,&b);
        sum += a * b;
    }
    printf("%.3lf\n",sum);
    return 0;
}        

