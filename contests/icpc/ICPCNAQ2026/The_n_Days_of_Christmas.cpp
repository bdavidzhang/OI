// The n Days of Christmas
// https://naq26.kattis.com/contests/naq26/problems/thendaysofchristmas2  (1000 ms, 2048 MB)
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

void debug(string s, vll &v){
  cout << s << endl;
  for(auto x : v) cout << x << " ";
    cout << endl;
}

const int MOD = 998244353;

ll mul(ll a, ll b, ll p =MOD){
  a %= p;
  if (a < 0) a += p;
  b %= p;
  if(b < 0) b += p;
  return (__int128) a * b % p;
}

ll qpow(ll a, ll b, ll p = MOD){
  if(b < 0) b += p;

  ll r = 1 % p;
  a %= p;
  if(a < 0) a += p;
  while(b){
    if(b & 1) r = mul(r,a,p);
    a = mul(a,a,p);
    b >>= 1;
  }
  return r;
}


void solve(ll n) {
  ll ans = 1;
  ans = mul(ans,n+2);
  ans = mul(ans,n+1);
  ans = mul(ans,n);
  ans = mul(ans,qpow(6,-2));

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  solve(n);

  return 0;
}
