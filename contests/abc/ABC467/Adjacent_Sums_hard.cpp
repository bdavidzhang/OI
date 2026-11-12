#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define pb push_back

struct Event{
  ll x;
  ll delta;
  bool operator<(Event other){
    return x < other.x;
  }
};

void solve(){
  int n,m;
  cin >> n >> m;
  vector<ll> A(n),B(n);
  vector<Event> events;
  for(int i = 0; i < n; ++i) cin >> A[i];
  for(int i = 0; i < n-1; ++i) cin >> B[i];
  
  auto mod = [&](ll x){
    return (x % m + m) % m;
  };
  
  ll c = 0;
  ll ini = 0;
  for(int i = 0; i < n; ++i){
    if(i % 2 ==0){
      ll t = mod(A[i] - c);
      ini += mod(-t);
      if(t > 0) events.pb({t,-1LL*m});
    }else{
      ll t = mod(c - A[i]);
      ini += mod(t);
      if(t + 1 < m) events.pb({t+1,(ll)m});
    }
    c = mod(B[i] - c);
  }
  ll slp = n % 2;
  
  sort(all(events));
  
  ll cur = ini;
  ll ans = ini;
  ll prev = 0;
  for(int i = 0; i < sz(events); ){
    ll x = events[i].x;
    ll dx = x - 1 - prev;
    cur += dx * slp;  
    ans = min(cur,ans);

    ll delta = 0; 
    while(i < sz(events) && events[i].x == x){
      delta += events[i].delta;
      i++;
    }

    cur += delta + slp;
    ans = min(cur,ans);
    prev = x;
  }
  ll dx = m - 1 - prev;
  cur += dx * slp;
  ans = min(cur,ans);

  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}