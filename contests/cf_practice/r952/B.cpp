#include<iostream>


int main(){
    int t;
    std::cin>>t;
    while(t--){

        int n;
        std::cin>>n; 

        int max = 0;
        int x;
        for (int i = 2; i <= n; ++i){
            int sum = 0;
            for (int j = i; j <= n; j+=i){
                sum += j;
            }
            if (max < sum){

                 max = sum;
                 x = i;
            }

        }

        std::cout<<x<<'\n';
    }

}
