//automatic answer
#include<cstdio>
#include<cmath>
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        n*=567;
        n/=9;
        n+=7492;
        n*=235;
        n/=47;
        n-=498;
        n/=10;
        printf("%d\n",std::abs(n%10));
    }
    return 0;
}
        
       
