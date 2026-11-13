// A. Three Piles
// https://codeforces.com/contest/2290/problem/A  (1000 ms, 256 MB)
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
  vi a(3);
  for(int i = 0; i < 3; ++i) cin >> a[i];
  sort(all(a));
  if(a[1] - 1 == a[0] && a[1] + 1 == a[2]) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
