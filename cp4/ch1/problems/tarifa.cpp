//tarifa.cpp
#include<cstdio>
int main(){
    int x, n, a, sum = 0,total;
    scanf("%d%d", &x, &n);
    total = x * (n+1);
    for (int i = 0 ; i < n; ++i){
        scanf("%d", &a);
        sum += a;
    }
    printf("%d\n", total - sum);
    return 0;
}

