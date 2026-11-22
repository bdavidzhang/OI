// Fairytale
// https://naq26.kattis.com/contests/naq26/problems/fairytale  (1000 ms, 2048 MB)
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
  vi cnt(4,0);
  for(int i =0 ;i < n; ++i){
    int x;
    cin >> x;
    x--;
    cnt[x/10] = 1;
  }

  ll ans =0 ;
  for(int i = 0; i< 4; ++i) ans += cnt[i];
  cout << ans << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
