#include<iostream>
#include<vector>

int main(){
    int N, C;
    std::cin>>N>>C;

    std::vector<long long> pref(N+1);
    std::vector<long long> ans(N+1);

    for (int i = 1; i < N+1; ++i){
        int n;
        std::cin>>n;
        pref[i] = pref[i-1]+n;
    }//maintain pref sums;
    
    int e =1;
    int s = 1;

    do{
        if(s <= e){
            ans[s]++;
            ans[e+1]--;
        } 
        if(e+1 > N) s++;
        else if ((pref[e+1] - pref[s-1]) > C) s++;
        else e++;
    
    }while(s <= N);
    
    long long sum = ans[0];
    for(int i = 1; i < N+1; ++i){
        sum += ans[i];
        std::cout<<sum<<std::endl;
    }

    return 0;
}
