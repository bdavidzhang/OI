// B - Monocolor
// https://atcoder.jp/contests/abc470/tasks/abc470_b  (2000 ms, 1024 MB)
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
  unordered_map<int,int> cnt; 
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    ++cnt[x];
  }

  auto it = max_element(cnt.begin(),cnt.end(), [](const auto & a, const auto & b){return a.second < b.second;});
  int ans = it->second;
  cout << n - ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
