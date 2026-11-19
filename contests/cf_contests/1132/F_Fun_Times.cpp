// F. Fun Times
// https://codeforces.com/contest/2284/problem/F  (2000 ms, 256 MB)
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

constexpr ll MOD = 1e9+7;

struct Mat {
  ll a[2][2] = {};

  static Mat identity() {
    Mat res;
    res.a[0][0] = res.a[1][1] = 1;
    return res; 
  }
};

Mat operator*(const Mat& A, const Mat& B){
  Mat C; 
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j)
      for(int k = 0; k < 2; ++k)
        C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
      
  return C;
}

struct SegTree {
  int n;
  vector<Mat> tr;

  SegTree(const vector<Mat> &a){
    n = 1;
    while(n < sz(a)) n <<= 1;


    tr.assign(2 * n, Mat::identity());

    for(int i = 0; i < sz(a);++i) tr[n+i] = a[i];

    for(int i = n -1; i >= 1; --i) tr[i] = tr[i << 1 ] * tr[i << 1 | 1];
  }

  void set(int pos, Mat val){
    pos += n;
    tr[pos] = val;
    for(pos >>= 1; pos; pos >>= 1) tr[pos] = tr[pos << 1] * tr[pos << 1 | 1];
  }

  Mat query(int l, int r){
    Mat left = Mat::identity();
    Mat right = Mat::identity();

    l += n;
    r += n;

    while(l < r){
      if(l & 1) left = left * tr[l++];
      if(r & 1) right = tr[--r] * right;

      l >>= 1;
      r >>= 1;
    }

    return left * right;
  }

};




void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<pii> A(2*n, {0,0});

  for(int i = 0; i < n; ++i){
    if(s[i] == '1') A[n+i] = {0,1};
    else A[n+i] = {1,0};
  }

  vll pw(n+1,1);
  for(int i = 1; i <= n; ++i) pw[i] = (pw[i-1] << 1) % MOD;

  auto segf = [&](int i) -> Mat{
    auto [b,a] = A[i];

    ll tot = pw[b];
    ll present;

    if(a > 0) present = tot;
    else present = (tot - 1 + MOD) % MOD;

    Mat M;
    M.a[0][0] = present;
    M.a[0][1] = present;
    M.a[1][1] = tot;

    return M;
  };

  vector<Mat> init(2 * n);
  for(int i = 0; i < 2 * n; ++i) init[i] = segf(i);

  SegTree seg(init);

  ll ans = 0;

  int L = n;
  int R = 2 * n;

  for(int mod = n - 1; mod >= 1; -- mod){
    for(int K = mod - 1; K < R - L; ++K){
      int a = L + K;
      int V = (K + 1 ) % mod; 
      int b = (L - 1) + V;

      if(a == b) continue;

      A[b].first += A[a].first;
      A[b].second += A[a].second;

      A[a] = {0,0};

      seg.set(a,segf(a));
      seg.set(b,segf(b));

    }

    --L;
    R = L + mod;

    Mat res = seg.query(L,R);
    ans = (ans + res.a[0][1]) % MOD;
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
