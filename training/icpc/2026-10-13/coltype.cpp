#include<bits/stdc++.h>
using namespace std;

using ll = unsigned __int128;


ll binexp(ll a, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) { 
            ans = ans * a;
        }
        a = a * a;  // Square the base
        n >>= 1;    // Right shift n by 1 (equivalent to n = n / 2)
    }
    return ans;
}



void solve(){
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  if((s.empty() || s.back() != 'O')) ok = false;
  for(int j = n-1; j > 0; j--){
    if(s[j] == s[j-1] && s[j] == 'O'){
      ok = false;
      break;
    }
  }
  if(!ok){
    cout << "INVALID" << '\n';
    return;
  }
  //cout << "got here" << endl;
  for(int j = 4; j <= 80; j+=2){
    ll x = (((ll)1 << j) - 1) / 3;
    bool good = true;
    
    //cout << j << ": ";
    for(int i = n-2; i >= 0; i--){
      //cout << x << " ";
      if(s[i] == 'O'){
        if(x < 10 || (x-1) % 3 != 0){
          good = false;
          break;
        }
        x = (x-1) / 3; 
        if(x % 2 == 0 || x <= 1){
          good = false;
          break;
        }
      }else{
        x = x * 2;
      }
    }
    //cout << endl; 
      if (good){
        string o;
        while(x > 0){
          o += ('0' + (int)(x % 10));
          x /= 10;
        }
        reverse(o.begin(),o.end());
        cout << o << '\n';
        return;
      }
  }
  cout << "INVALID" << '\n';
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
