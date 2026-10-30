#include<cstdio>
#include<cmath>
int main(){
    int a, i;
    scanf("%d%d", &a,&i);
    double t = a * (i-0.5);
    int ans;
    if (std::floor(t) == t){
        ans = floor(t)+1;
    }
    else{
        ans = ceil(t);
    }
    printf("%d",ans);
    return 0;
}
