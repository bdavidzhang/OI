#include<iostream>
#include<vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<long long> arr(n+1,0);
    for (int i = 1; i <= n; ++i){
        std::cin >> arr[i];
    } 

    std::vector<std::vector<int> > ops(m+1,std::vector<int>(3));
    for(int i = 1; i <= m; ++i){
        std::cin>> ops[i][0] >> ops[i][1] >> ops[i][2];
    }
    std::vector<long long> opscnt(m+2,0);
    for (int i = 0; i < k; ++i){
        int a,b;
        std::cin>>a>>b;
        opscnt[a]++;
        opscnt[b+1]--;
    }

    for (int i = 1; i <= m; ++i){
        opscnt[i] += opscnt[i-1];
    }

    std::vector<long long> diff(n+2,0);
    for (int i = 1; i <= m; ++i){
        diff[ops[i][0]] += opscnt[i] * ops[i][2] * 1LL;
        diff[ops[i][1]+1] -= opscnt[i] * ops[i][2] * 1LL;
    }

    for (int i = 1; i <= n; ++i){
        diff[i] += diff[i-1];
        arr[i] += diff[i];
        std::cout<<arr[i] << ' ' ;
    }
    std::cout << '\n';

    return 0;
}
