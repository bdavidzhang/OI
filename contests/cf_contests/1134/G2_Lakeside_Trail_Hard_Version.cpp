// G2. Lakeside Trail (Hard Version)
// https://codeforces.com/contest/2290/problem/G2  (4000 ms, 256 MB)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'

void solve() {
  ll n, k;
  cin >> n >> k;
  vi h(n);
  for(int i = 0; i < n; ++i) cin >> h[i];

  auto check = [&](ll d){
    vll a(all(h));
    int maxi = INT_MIN, m;
    for(int i = 0 ;i < n; ++i){
      if(maxi < h[i]){
        maxi = h[i]; m = i;
      }
    }

    for(int i = 1; i <= n; ++i){
      a[(m+i) % n] = max(a[(m+i) % n],a[(m+i-1) % n] - d);
    }

    for(int i = 1; i <= n; ++i){
      a[(m+n-i) % n] = max(a[(m+n-i) % n],a[(m+n-i+1) % n] - d);
    }

    ll cost = 0;
    for(int i = 0 ;i < n; ++i) cost += abs(a[i] - h[i]);

    return k >= cost;
  };

  ll l = -1, r = 1e9;
  while(r - l != 1){
    int mid = l + (r - l) / 2;
    if(check(mid)) r = mid;
    else l = mid;
  }
  cout << r << endl;
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
