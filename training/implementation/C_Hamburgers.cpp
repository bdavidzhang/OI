#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define int long long
#define sz(x) ((int)(x).size())
using vi = vector<int>;

void solve(){
  string s;
  cin >> s;

  vi n(3), p(3), c(3,0);
  for(int i = 0; i < 3; ++i){
    int x;
    cin >> x;
    n[i] = x;
  }
  for(int i = 0; i < 3; ++i){
    int x;
    cin >> x;
    p[i] = x;
  }

  int tot;
  cin >> tot;

  for(int i = 0; i < sz(s); ++i){
    if(s[i] == 'B') c[0]++;
    if(s[i] == 'S') c[1]++;
    if(s[i] == 'C') c[2]++;
  }

  auto check = [&](int x){
    int cost = 0;
    for(int i = 0; i < 3; ++i){
      cost += max(x * c[i] - n[i],(int)0) * p[i];
    }
    return tot >= cost;
  };



  int l = 0, r = 1e13;
  while(r - l > 1){
    int mid = l + (r - l) / 2;
    if(check(mid)) l = mid; 
    else r = mid;
  }
  cout << l << endl;
}


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();


  return 0;
}

