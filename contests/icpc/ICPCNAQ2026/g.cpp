#include<bits/stdc++.h>
using namespace std;


void solve(){
  int p,q,g;
  cin >> p >> q >> g;
  unordered_map<int,int> ptog, cnt;
  for(int j = 0; j < q; ++j){
    char c;
    cin >> c; 
    if(c == 'P'){
      int s,a;
      cin >> s >> a;
      while(a--){
        int p; cin >> p;
        auto it = ptog.find(p);
        if (it != ptog.end()){
          cnt[it->second]--;
          it->second = s; 
        }else{
          ptog[p] = s;
        }
        cnt[s]++; 
      }
    }else{
      int s;
      cin >> s;
      auto it = cnt.find(s);
      if(it == cnt.end()) cout << 0;
      else cout << it->second;
      cout << '\n';
    }
  }
  //maintain the last danced to genere
  //and maintain the total amount of dancers / genre


}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}