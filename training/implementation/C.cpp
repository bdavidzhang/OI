#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) ((int)(x).size())

void solve(){
  string s;
  cin >> s;
  int nb, nh, nc;
  cin >> nb >> nh >> nc;
  int pb,ph,pc;
  cin >> pb >> ph >> pc;
  int cb=0,ch=0,cc=0;
  int tot; cin >> tot;

  for(int i = 0; i < sz(s); ++i){
    if(s[i] == 'B') cb++;
    else if(s[i] == 'S') ch++;
    else cc++;
  }

  int l = 0, r = 1e13;

  auto check = [&](int x){//make x 
    int cst = (x * cb - nb) * pb + (x * ch - nh) * ph + (x * cc - nc) * pc; 
    return tot >= cst;
  };


  while(l != r){
    int m = (l+r) >> 1;
    if(check(m)) l = m;
    else r = m - 1;
  }
  cout << l << endl;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();


  return 0;
}
