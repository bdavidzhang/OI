// B. Stubborn Pen
// https://codeforces.com/contest/2290/problem/B  (2000 ms, 256 MB)
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
  string s;
  cin >> s;

  ll ans = 0;
  char c = 'R';

  auto tog = [&](char c){
    if( c== 'R') return 'B';
    else return 'R';
  };

  for(int i = 0 ;i < n; ++i){
    if(s[i] != c){
      ans++; 
      c = tog(c);
    }
    c = tog(c);
  }
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
