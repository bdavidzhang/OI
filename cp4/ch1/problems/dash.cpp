//horror dash
#include<cstdio>
int main(){
    int t,n,max=-1,x; 
    scanf("%d",&t);
    for (int j = 1; j <= t; ++j){
        max = -1;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&x);
            if(max < x) max = x;
        }
        printf("Case %d: %d\n", j, max);
    } 
    return 0;
}

