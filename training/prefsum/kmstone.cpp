#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    int n;
    std::cin>> n;
    std::vector<long long> arr(n+1,0);
    std::vector<long long> brr(n+1,0);
    std::vector<long long> suma(n+1,0),sumb(n+1,0);//used as a placeholder

    for (int i =1; i <= n; ++i){
        std::cin>>arr[i];
        brr[i] = arr[i];
    }

    std::sort(brr.begin(),brr.end());

    for (int i = 1; i <= n; ++i){
        suma[i] = arr[i] + suma[i-1];
        sumb[i] = brr[i] + sumb[i-1];
    }
    //prefix sums done

    int m;
    std::cin>>m;

    for (int i = 0; i < m; ++i){
        int t,l,r;
        std::cin>>t>>l>>r;
        if(t == 1){
            std::cout<<suma[r]-suma[l-1]<<'\n';
        }
        else{
            std::cout<<sumb[r]-sumb[l-1]<<'\n';
        }
    }
    return 0;
}


              
    
