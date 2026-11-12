// A - π
// https://atcoder.jp/contests/abc449/tasks/abc449_a  (2000 ms, 1024 MB)
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

const double PI = acos(-1.0);

void solve() {
  double D;
  cin >> D;
  double R = D / 2;
  cout << PI * R * R << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(15) << fixed; 


  int T = 1;
  while (T--) solve();
  return 0;
}
