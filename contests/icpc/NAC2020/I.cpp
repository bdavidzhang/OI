#include<bits/stdc++.h>
#include <cmath>
#include <iterator>
#include <system_error>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
#define sz(x) ((int)(x).size())

constexpr int MOD = 998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int d;
  cin >> s >> d;
  int n = sz(s);

  vi pow3(n+1,1);
  for(int j = 1; j <= n; ++j)
    pow3[j] = 3 * pow3[j - 1];

  int states = pow3[n];

  // letters in s are treated equally, others 
  // use one transition
  vector<pair<char,char>> letters; 
  int other = 26; 
  for(char c = 'A'; c <= 'Z'; ++c){
    if (s.find(c) != string::npos){
      letters.emplace_back(c,1);
      --other;
    }
  }

  if(other > 0) letters.emplace_back('#',other);

  int kinds = sz(letters);

  vector go(states, vi(kinds));
  vi offset(states);
  vi row(n+1), next_row(n+1);

  for(int st = 0; st < states; ++st){
    row[0] = 0;
    int code = st;
    for(int j = 1; j <= n; ++j){
      row[j] = row[j-1]  + code % 3  -1;
      code /= 3;
    }
    offset[st] = row[n];

    for(int k = 0; k < kinds; ++k){
    char c = letters[k].first;

    next_row[0] = 1;
    int to = 0;
    for(int j = 1; j <= n; ++j){
        next_row[j] = min({
                  row[j] + 1,
                  next_row[j-1] + 1,
                  row[j-1] + (s[j-1] != c)
                  });
        int digit = next_row[j] - next_row[j-1] + 1;
        to += digit * pow3[j - 1];
      }
    go[st][k] = to;
    }
  }
  
  vi dp(states), ndp(states);
  dp[states - 1] = 1;

  int ans = 0;
  for(int len = 0; len <= n + d; ++len){
    for(int st = 0; st < states; ++st){
      if(len + offset[st] == d){
        ans += dp[st];
        if (ans >= MOD) ans -= MOD;
      }
    }

    if(len == n + d) break;

    fill(ndp.begin(), ndp.end(), 0);
    for(int st = 0; st < states; ++st){
      if(dp[st] == 0) continue;

      for(int k = 0; k < kinds; ++k){
        int to = go[st][k];
        int mul = letters[k].second;
        int add = 1LL * dp[st] * mul % MOD;
        ndp[to] += add;
        if(ndp[to] >= MOD) ndp[to] -= MOD;
      }
    }
    dp.swap(ndp);
  }

  cout << ans << endl;
  return 0;
}



