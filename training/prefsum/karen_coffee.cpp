//use a prefix sum and a difference array
#include<iostream>
#include<vector>

const int len = 200000 + 10;

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n,k,q;
    std::cin>>n>>k>>q;

    std::vector<int> v(len,0);
    std::vector<int> c(len,0);

    for (int i = 0; i < n ; ++i){
        int l, r;
        std::cin >> l >> r;
        v[l]++;
        v[r+1]--;
    }

    
    for (int i = 1; i <= len; ++i){
        v[i] += v[i-1];
        c[i] = c[i-1];
        if(v[i] >= k) c[i]++; 
    }        
    
    for (int i = 0; i < q; ++i){
        int l,r;
        std::cin>>l>>r;
        std::cout<<c[r]-c[l-1]<<'\n';
    }


   return 0;
} 


