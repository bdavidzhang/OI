// D - Make Target 2
// https://atcoder.jp/contests/abc449/tasks/abc449_d  (2000 ms, 1024 MB)
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

void solve() {
  ll L, R , D, U;
  cin >> L >> R>> D>> U;
  
  auto f = [&](ll k) -> ll{
    if(k < 0) return 0;
    ll cand = max((ll)0,(min(R,k) - max(L,-k) + 1)) * max((ll)0,(min(U,k) - max(D,-k) + 1));
    return max(cand,(ll)0);
  };
  ll ans = 0;
  for(int k = 0; k <= max({abs(L),abs(R),abs(D),abs(U)}); k += 2){
    ans += f(k) - f(k-1);
  }
  cout << ans << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
