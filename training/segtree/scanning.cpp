#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Event{
  ll x;
  ll delta;
  bool operator<(Event other){
    return x < other.x;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int,int>> intervals = {{1,5},{3,7},{4,6}};
  vector<Event> events;
  for(auto [a,b] : intervals){
    events.push_back({a,+1}); 
    events.push_back({b,-1});
  }
  sort(events.begin(),events.end());

  ll cnt = 0, ans = 0;
  ll prev = 0;
  for(auto e: events){
    if(cnt >= 2) ans += e.x - prev;
    cnt += e.delta;
    prev = e.x;
  } 
  cout << ans << endl;


  return 0;
}