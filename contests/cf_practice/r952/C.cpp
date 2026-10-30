#include<iostream>
#include<algorithm>

int main(){
    int t;
    std::cin>>t;
    while(t--){

        int n;
        std::cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i){
            std::cin>> arr[i];
        } 
        long long sum = 0;
        int mx = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i){
        sum += arr[i];
        mx = std::max(mx,arr[i]);
        if(sum - mx == mx) ans++;
        }
        std::cout<<ans<<'\n';
    
    }

}
