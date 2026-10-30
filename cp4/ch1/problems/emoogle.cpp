//emoogle balance
#include<cstdio>
int main(){
    int n, cs=0, cnt = 0, x;
    while (scanf("%d",&n)){
        if (n == 0) return 0;
        cnt = 0;
        cs++;
        while(n--){
        scanf("%d", &x);
        if(x == 0){
            cnt--;
        }else{
            cnt++;
        }
        }
        printf("Case %d: %d\n", cs, cnt);
    }
}
