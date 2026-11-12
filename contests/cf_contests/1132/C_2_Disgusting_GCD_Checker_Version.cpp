
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()
#define int long long
#define sz(x) ((int)(x).size())

const int MAXN = 2e5;
vector<bool> is_prime(MAXN, true);
vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < MAXN; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXN; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i < MAXN; ++i)
        if (is_prime[i])
            primes.push_back(i);
}


pair<int, vector<int>> small_dp(int a, int b) {
    int D = b - a;
    vector<int> dp(D + 1, D + 1);
    vector<int> par(D + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= D; ++i) {
        for (int j = 0; j < i; ++j) {
            if (gcd(a + j, i - j) == 1 &&
                dp[j] + 1 < dp[i]) {
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
    }

    vector<int> path;
    for (int cur = D; cur != -1; cur = par[cur])
        path.push_back(a + cur);

    reverse(path.begin(), path.end());
    return {dp[D], path};
}

void solve(){
  int a, b;
  cin >> a >> b;
  if(a == b){
    cout << 0 << '\n';
    return;
  }
  if(gcd(a,b) == 1){
    cout << 1 << '\n';
    cout << b - a << '\n';
    return;
  }
  if(b - a <= 100){
    auto [ans, path] = small_dp(a,b);
    cout << ans << '\n';
    for(int i = 1; i < sz(path); ++i) cout << path[i] - path[i-1]<< " ";
    cout << '\n';
  }else{
    auto it = upper_bound(all(primes),a);
    while(it != primes.end() && b % *it == 0) it++;
    int p = *it;
    cout << 2 << '\n';
    cout << p - a << " " << b - p << '\n';

  }
}



signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >>T ;
  sieve();
  while(T--)solve();


  return 0;
}

