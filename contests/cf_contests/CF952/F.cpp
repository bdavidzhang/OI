#include<bits/stdc++.h>
using namespace std;


using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;

ll gcd(int a, int b){
    if(a < b) swap(a,b);
    return (b==0)?a : gcd(b, a%b);
}

ll lcm(vi &c){
   ll ans = c[0];
   for(int i = 1; i < c.size(); ++i){
        ans = ((c[i]*ans)/(gcd(ans,c[i])));
   }
   return ans;
    
}

void solve(){

    int h, n;
    cin >> h >> n;

    vi a(n),c(n);
    for(auto &x : a) cin >> x;
    for(auto &x : c) cin >> x;
    
    set<pair<ll, int>> S;
    for(int i = 0; i < n; ++i){
        S.insert({1,i}); 
    }
    
    ll ans = 1;

    while(h > 0){
        auto [turn, i] = *S.begin();
        S.erase(S.begin());
        ans = turn;
        h-=a[i];
        S.insert({turn+c[i],i});
    }
    cout << ans << endl;

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve(); 
    }


    return 0;
}
