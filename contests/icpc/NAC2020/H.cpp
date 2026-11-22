#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
using vi = vector<int>; 
using pii = pair<int,int>;

#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define sz(x) ((int)(x).size())

void solve(){
  string a, b, c;
  cin >> a >> b >> c;

  int n = sz(a);
  b = b + b; 
  c = c + c;

  auto dist = [&](int shift){
    shift = abs(shift);
    return min(shift, n - shift);
  };

  string need(n, ' ');
  vi pi(n);

  int ans = INT_MAX;

  for(int x = 0; x < n; ++x){
    bool ok = true;
    for(int i = 0 ; i < n; ++i){
      if(a[i] == b[i+x]){
        ok = false;
        break;
      }
      need[i] = 'A' + 'B' + 'C' - a[i] - b[i+x];
    }

    if(!ok) continue;

    pi[0] = 0;
    for(int i = 1; i < n; ++i){
      int j = pi[i-1];
      while(j > 0 && need[i] != need[j]){
        j = pi[j-1];
      }
      if(need[i] == need[j]) ++j;
      pi[i] = j;
    }

    for(int i = 0, j = 0; i < 2 * n - 1; ++i){
      while (j > 0 && c[i] != need[j]) 
        j = pi[j-1];
      if(c[i] == need[j]) j++;

      if(j == n){
        int y = i - n + 1;
        int ab = dist(x);
        int ac = dist(y);
        int bc = dist(y - x);

        ans = min({ans, ab + ac, ab + bc, ac + bc});
        j = pi[j-1];
      }
    }
  }

  cout << (ans == INT_MAX ? -1 : ans) << endl;

}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  


  return 0;

}
