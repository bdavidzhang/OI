#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

const long long MOD = 998244353;
const int inf = 1e9;


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin>>n;
    std::vector<int> dp(inf);

    int target = (((n+1)/2) % MOD) * (n % MOD);

 
    //how to manage permutation
    std::vector<int> perm(n);

               



    return 0;
}
