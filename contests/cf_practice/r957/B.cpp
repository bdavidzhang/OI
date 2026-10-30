#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin>>t;
    while(t--){
        int n,k;
        std::cin>>n>>k;
        int max = -1;
        for (int i = 0; i < k; ++i){
            int temp;
            std::cin>>temp;
            if (max < temp){
            max = temp;
            }
        } 
        long long res = 0;
        res = n - max + n - max - (k-1);
        std::cout<<res<<'\n';
    }

    return 0;

}
