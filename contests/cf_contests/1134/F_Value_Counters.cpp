// F. Value Counters
// https://codeforces.com/contest/2290/problem/F  (2000 ms, 256 MB)
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

  vi pos(n+1);
  bool ok = true;
  for(int x =1; x <= n; ++x){
    int b;
    cin >> b;
    int j = b - x + n + 1;
    if(j < 1 || j > n || pos[j] != 0) ok = false; 
    else pos[j] = x;
  }
  if(!ok) cout << -1 << endl;
  else{
    for(int j = 1; j <= n; ++j) cout << pos[j] << " ";
    cout << endl;
  }
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
