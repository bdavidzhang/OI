#include<bits/stdc++.h>
#include <iterator>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
#define sz(x) ((int)(x).size())

constexpr int MOD = 998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  ll t;
  cin >> n >> t;
  
  vi a(n);
  ll idle = t;
  for(int & x : a){
    cin >> x;
    idle -= x;
  }

  ll ans = idle + 1;
  ll choices = n + idle + 1;

  for(int i = 0; i < n;++i){
    if(i > 0)
      ans = ans * choices % MOD;

    choices += a[i] - 1;
  }

  cout << ans << endl;

  return 0;
}




