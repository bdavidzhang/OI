// B. Always Changing
// https://codeforces.com/group/tKC7z9Nm0A/contest/732255/problem/B  (1500 ms, 256 MB)
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

  vi cnt(2,0), tot(2,0); 
  for(int i = 0; i < n; ++i){
    tot[s[i] - '0']++;
  }
  for(int c : {0,1}){
    int p = c;
    for(int i = 0; i < n; ++i){
      if(s[i] - '0' == p){cnt[c]++,p ^= 1;} 
    }
  }
  int ans = INT_MAX;
  for(int c : {0,1}){
    for(int s = 0; s <= 1; ++s){
      vi k(2),d(2);
      int L = cnt[c] - s;
      if(L <= 0) continue;
      k[c] = (L + 1) / 2;
      k[c^1] = L / 2;
      for(auto p : {0,1}) d[p] = tot[p] - k[p];
      if(abs(d[0] - d[1]) <= 1) ans = min(ans,d[0]+d[1]);
    }
  } 

  cout << ((ans == INT_MAX) ? -1 : ans) << endl;    
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
