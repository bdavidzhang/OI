
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()
#define int long long


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

void solve(){
  int n;
  cin >> n;
  vi v(n);
  for(int i = 0; i < n;++i){
    cin >> v[i];
    int idx = lower_bound(all(primes),v[i]) - primes.begin();
    v[i] = primes[idx];
  }
  for(int a: v) cout << a << " ";
  cout << '\n'; 
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

