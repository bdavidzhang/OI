#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

pair<ll,ll> partition(const vector<long long>& a) { 
    long long s1 = 0, s2 = 0;

    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (s1 <= s2) {
            s1 += a[i];
        } else {
            s2 += a[i];
        }
    }
    return {s1,s2};
}


void solve(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i){
    int p;
    cin >> p;
    a[i] = 1 << p;
  }
  sort(all(a));
  pair<ll,ll> ans = partition(a);
  cout << (ll) ans.first * ans.second << '\n';
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >>T ;
  while(T--)solve();


  return 0;
}

