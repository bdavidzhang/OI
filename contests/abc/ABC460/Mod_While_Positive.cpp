#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first 
#define se second
using ll = long long;
using vi = vector<int>;


void solve(){
  int n,m;
  cin >> n >> m;
  ll cnt = 0;
  while(m != 0){
    m = (n % m);
    cnt++;
  }
  cout << cnt << endl;
  
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}