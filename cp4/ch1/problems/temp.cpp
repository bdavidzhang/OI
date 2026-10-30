//temperature.cpp
#include<cstdio>
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    if (x == 0 && y == 1) printf("ALL GOOD");
    else if (y == 1) printf("IMPOSSIBLE");
    else printf("%.6lf",static_cast<double>(x)/(1-y));
    return 0;
}
