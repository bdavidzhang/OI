#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;


int main(){
    int n,k;
    cin >> n >> k;
    vi a(n+1);
    for(int i =1; i<= n; ++i) cin >>a[i];
    for(int i = n-k+1; i <= n; ++i){
        cout<<a[i] << " "; 
    }
    for(int i = 1; i <= n-k; ++i){
        cout<<a[i] << " "; 
    }
    cout << endl;


    return 0;
}
