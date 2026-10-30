#include<iostream>
#include<vector>
#include<string>

void solve(){
    int n;
    std::string s;
    std::cin>>n>>s;

    int res = n-1;
    for(int i = 1; i < n-1; ++i){
        if(s[i-1] == s[i+1]) res--;
    } 

    std::cout<<res<<'\n';
}


int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin>>t;
    while(t--){
        solve();
    }


    return 0;
}
