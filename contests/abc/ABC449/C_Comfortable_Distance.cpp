// C - Comfortable Distance
// https://atcoder.jp/contests/abc449/tasks/abc449_c  (2000 ms, 1024 MB)
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
  ll n;
  ll L,R;
  cin >> n >> L >> R;
  string s;
  cin >> s;
  ll ans=0;
  vector<ll> cnt(26,0);
  int i = 0, j = 0;
  while(j < n){
    int idx = (int)(s[j]-'a');
    ans += cnt[idx];
    cnt[idx]++;
    ans++;
    if(j - i < R) j++;
    else{
      idx = (int)(s[i]-'a');
      cnt[idx]--;
      i++;
      j++;
    }
  }

  //cout << ans << endl;


  ll sub = 0;
  i = 0, j = 0;
  cnt.assign(26,0); 
  while(j < n){
    int idx = (int)(s[j]-'a');
    sub += cnt[idx];
    cnt[idx]++;
    sub++;
    if(j - i < L-1) j++;
    else{
      idx = (int)(s[i] - 'a');
      cnt[idx]--;
      i++;
      j++;
    }
  }

  ans -= sub;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
