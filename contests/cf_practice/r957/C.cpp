#include<iostream>
#include<vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--){
        int n,m,k; 
        std::cin>>n>>m>>k;
        for (int i = n; i > m; i--){
            std::cout<< i << ' '; 
        }
        for (int i = 1; i <= m; i++){
            std::cout << i << ' '; 
        }
        std::cout <<'\n';

    }


    return 0;

}
