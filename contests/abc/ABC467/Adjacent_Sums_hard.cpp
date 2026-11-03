#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

struct Event {
    ll x;
    ll delta; 
    bool operator<(const Event& other) const {
        return x < other.x;
    }
};



ll min_cost(
  vector<Event> events,
  ll init_cost,
  ll slope,
  ll m
) {
  sort(all(events));
  ll current_active = init_cost;
  ll min_active = current_active;
  ll prev = 0;
  
  for(int i = 0; i < (int)events.size(); ){
      ll x = events[i].x;

      current_active += (x - 1 - prev) * slope;
      min_active= min(min_active, current_active);

      ll delta = 0;
      while (i < (int)events.size() &&
              events[i].x == x) {
          delta += events[i].delta;
          i++;
      }

      current_active += slope + delta;
      min_active= min(min_active,current_active);

      prev = x;
  }
  current_active += (m - 1 - prev) * slope;
  min_active = min(min_active,current_active);

  return min_active;
}

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vi A(n), B(n - 1);

    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;

    auto mod = [&](ll x) -> ll {
      return (x % m + m) % m;
    };
    vector<Event> events;

    ll initial_cost = 0;
    ll slope = 0;
    ll c = 0;
    
    for(int i = 0; i < n; ++i){
      if(i % 2 == 0) {
        ll t = mod(A[i] - c);
        initial_cost += mod(-t);
        slope++;
        if(t > 0) events.push_back({t, -1LL * m});
      }else{
        ll t = mod(c - A[i]);
        initial_cost += mod(t);
        slope--;
        if(t + 1 < m) events.push_back({t+1, (ll)m});
      }
      if(i < n -1 ){
        c = mod(B[i] - c);
      }
    }
    cout << min_cost(events, initial_cost, slope, m) << endl;
}




