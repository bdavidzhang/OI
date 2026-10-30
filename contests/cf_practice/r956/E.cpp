#include<iostream>
#include<cstdio>

#define Mod 10^9+7

int main(){
    
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        long long sum = 0;
        long long A = 0;
        long long sumk = 0;
        long long sumo = 0;
        scanf("%d%d",&n,&k);
        std::vector<int> v(n); 
        for (int i =0; i<n; ++i){
            scanf("%d",&v[i]);
            sum += v[i];
            if(i < k) sumk += v[i];
        }

    }


    return 0;
}
