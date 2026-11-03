#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll r,c,d; int n;
  cin >> r >> c >> d >> n;
  vector<pair<ll,ll>> s(n);
  for(auto&p:s) cin >> p.fi >> p.se;
  sort(s.begin(),s.end());



  vector<ll> w(d+1);
  for(ll dy=0;dy<=d;dy++){
      ll t=d*d-dy*dy, x=sqrtl((long double)t);
      while(x*x>t) x--; while((x+1)*(x+1)<=t) x++;
      w[dy]=x;
  }


  vector<pair<ll,ll>> m;
  for(auto&p:s){
      ll a=max(1LL,p.first-d), b=min(r,p.first+d);
      if(!m.empty() && a<=m.back().second+1) m.back().second=max(m.back().second,b);
      else m.push_back({a,b});
  }

  ll covered=0; for(auto&g:m) covered+=g.second-g.first+1;
  if(covered<r){ puts("0"); return 0; }
  int ans=INT_MAX, lo=0, hi=0;
  vector<ll> L,R,occ,cand;
  for(auto&g:m) for(ll row=g.first;row<=g.second;row++){
      while(hi<n && s[hi].first<=row+d) hi++;
      while(lo<hi && s[lo].first<row-d) lo++;
      L.clear(); R.clear(); occ.clear(); cand.clear();
      cand.push_back(1);
      for(int k=lo;k<hi;k++){
          ll dy=llabs(s[k].first-row), ww=w[dy];
          ll a=max(1LL,s[k].second-ww), b=min(c,s[k].second+ww);
          L.push_back(a); R.push_back(b); cand.push_back(a);
          if(b+1<=c) cand.push_back(b+1);
          if(dy==0){ occ.push_back(s[k].second); if(s[k].second+1<=c) cand.push_back(s[k].second+1); }
      }
      sort(L.begin(),L.end()); sort(R.begin(),R.end());
      sort(occ.begin(),occ.end()); sort(cand.begin(),cand.end());
      cand.erase(unique(cand.begin(),cand.end()),cand.end());
      size_t pl=0,pr=0,po=0;
      for(ll x:cand){
          while(pl<L.size() && L[pl]<=x) pl++;
          while(pr<R.size() && R[pr]<x) pr++;
          while(po<occ.size() && occ[po]<x) po++;
          if(po<occ.size() && occ[po]==x) continue;
          ans=min(ans,(int)(pl-pr));
      }
  }
  cout << ans << endl;
}
