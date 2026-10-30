#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin>>t;
    while(t--){
        std::vector<int> v(3);
        std::cin>>v[0]>>v[1]>>v[2];
        for (int i = 0; i < 5; ++i){
        std::sort(v.begin(),v.end());
        v[0] += 1;
         
        }
        std::cout<<v[0]*v[1]*v[2]<<'\n'; 
    
    
    }

    return 0;

}
