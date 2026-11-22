// Airtime
// https://naq26.kattis.com/contests/naq26/problems/airtime  (2000 ms, 2048 MB)
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
  int n;
  cin >> n;
  vi d(n-1), a(n);
  for(int i = 0;i < n; ++i) cin >> a[i];
  for(int i = 0; i < n-1; ++i) d[i] = a[i+1] - a[i];
  ll ans = 0;
  for(int i = 0; i < n-2; ++i){
    if(d[i] > d[i+1]) ans++;
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
