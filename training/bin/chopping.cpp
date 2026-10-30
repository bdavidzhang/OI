//Chopping - LUOGU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;

bool check(vll &v, ll mid, ll M, ll n){
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if(v[i] - mid > 0)  sum += v[i] - mid;
    }
    return sum >= M;

}
void solve(){
    int n, m;
    cin >> n >> m;

    vll v(n);
    ll hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];  
        hi = max(hi,v[i]); 
    }
    hi--;
    ll lo = 0;
    ll mid ;
    while(lo < hi){ 
        mid = (lo+hi+1)/2; 
       if(check(v,mid,m,n)){
         lo = mid;
       }else{
         hi = mid - 1; 
       }
    }
    if(hi == lo) mid = hi;
    cout << mid << endl;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
