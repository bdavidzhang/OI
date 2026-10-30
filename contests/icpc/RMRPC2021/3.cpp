#include<iostream>
#include<vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin>>n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; ++i){
        std::cin>>arr[i];
    }

    std::sort(arr.begin(),arr.end(),std::greater<int>());

    long long ans = 0;

    for(int i = 0; i <n; ++i){
        if(i < n/2){
            ans += arr[i];
        }else{
            ans += arr[i]/2;
        }
    }

    std::cout<<ans<<std::endl;
    return 0;
}
